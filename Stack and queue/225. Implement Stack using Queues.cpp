class MyStack {
private:
    queue<int>que;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size=que.size();
        size--;
        while(size--){
            que.push(que.front());
            que.pop();
        }
        int ret=que.front();
        que.pop();
        return ret;
    }
    
    int top() {
        int size=que.size();
        size--;
        while(size--){
            que.push(que.front());
            que.pop();
        }
        int ret=que.front();
        que.push(ret);
        que.pop();
        return ret;  
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */