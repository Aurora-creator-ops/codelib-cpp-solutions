class Solution {
public:
    struct MyComparison{
        bool operator()(const pair<int,int>l,const pair<int,int>r)const{
            return l.second>r.second;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int,int>>, MyComparison> pri_que;
        for(auto it:map) {
            pri_que.push(it);
            if(pri_que.size()>k){
                pri_que.pop();
            }
        }


        //倒序输出
        vector<int>ret(k);
        for(int i=k-1;i>=0;i--){
            ret[i]=pri_que.top().first;
            pri_que.pop();
        }
        return ret;
    }
};