class Solution {
public:
    // 左闭右闭区间 [left, right]
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int middle = left + (right - left) / 2; // 避免溢出
            if (nums[middle] > target) {
                right = middle - 1;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                return middle; // 找到目标，返回下标（插入位置即目标下标）
            }
        }
        return right + 1; // 未找到，返回插入位置下标
    }

    // 左闭右开区间 [left, right)
    // int searchInsert(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size();
    //     while (left < right) {
    //         int middle = left + (right - left) / 2;
    //         if (nums[middle] > target) {
    //             right = middle;
    //         } else if (nums[middle] < target) {
    //             left = middle + 1;
    //         } else {
    //             return middle; // 找到目标，返回下标（插入位置即目标下标）
    //         }
    //     }
    //     return right; // 未找到，返回插入位置下标
    // }
};