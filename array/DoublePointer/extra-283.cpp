class Solution {
private:
    void swap(int &a,int &b){
        int temp=a;
        a=b;
        b=temp;
    }
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=0){
                swap(nums[slow++],nums[fast]);
            }
        }
    }
};