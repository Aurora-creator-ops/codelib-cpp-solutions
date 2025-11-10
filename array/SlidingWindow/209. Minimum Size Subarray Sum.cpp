class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0;
        int sum=0;
        int subLength=0;
        int result=INT_MAX;
        for(int j=0;j<nums.size();j++){
            sum+=nums[j];
            while(sum>=target){
                subLength=j-i+1;
                sum-=nums[i++];
                result=min(result,subLength);
            }
        }
        return result==INT_MAX?0:result;
    }
};