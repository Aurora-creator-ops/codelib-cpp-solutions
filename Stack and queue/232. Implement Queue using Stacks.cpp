class MyQueue {
private:
    stack<int>stackIn;
    stack<int>stackOut;

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        stackIn.push(x);
    }
    
    int pop() {
        if(stackOut.empty()){
            while(!stackIn.empty()){
                stackOut.push(stackIn.top());
                stackIn.pop();
            }
        }
        int res=stackOut.top();
        stackOut.pop();
        return res;
    }
    
    int peek() {
        //return stackOut.top();————>错误：因为在StackOut为空的时候会报错，要使用下列方法
        int res=this->pop();
        stackOut.push(res);
        return res;
    }
    
    bool empty() {
        return stackIn.empty() && stackOut.empty(); 
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */