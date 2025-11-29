class Solution {
private:
    class MyQueue{
    public://这一行必须要有，不带上会报错
        deque<int>que;

        void pop(int val){
            if(!que.empty() && val==que.front()){
                que.pop_front();
            }
        }

        void push(int val){
            while(!que.empty() && val>que.back()){
                que.pop_back();
            }
            que.push_back(val);
        }

        int front(){
            return que.front();
        }
    };

public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int>ret;

        for(int i=0;i<k;i++){
            que.push(nums[i]);
        }
        ret.push_back(que.front());

        for(int i=k;i<nums.size();i++){
            que.pop(nums[i-k]);
            que.push(nums[i]);
            ret.push_back(que.front());
        }

        return ret;
    }
};