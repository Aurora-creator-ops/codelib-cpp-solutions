class Solution {
public:
    // int removeElement(vector<int>& nums, int val) {
    //     //暴力实现:
    //     int ret=nums.size();
    //     for(int i=0;i<ret;i++){//这里必须是i<ret，不是i<nums.size()，因为数组的大小一直在变
    //         if(nums[i]==val){
    //             for(int j=i+1;j<ret;j++){//同上
    //                 nums[j-1]=nums[j];
    //             }
    //             ret--;
    //             i--;//注意，i必须要--
    //         }
    //     }
    //     return ret;
    // }

    int removeElement(vector<int>& nums, int val) {
        //双指针:注意，Fast和slow指针代表的含义
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
                nums[slow++]=nums[fast];
            }
        }
        return slow;
    }
};