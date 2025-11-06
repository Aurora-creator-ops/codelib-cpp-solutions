class Solution {
public:
    // 左闭右闭区间 [left, right]
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2; // 避免溢出
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                return mid; // 找到目标，返回下标
            }
        }
        return -1; // 未找到
    }

    // 左闭右开区间 [left, right)
    // int search(vector<int>& nums, int target) {
    //     int left = 0, right = nums.size();
    //     while (left < right) {
    //         int mid = left + (right - left) / 2;
    //         if (nums[mid] > target) {
    //             right = mid;
    //         } else if (nums[mid] < target) {
    //             left = mid + 1;
    //         } else {
    //             return mid; // 找到目标，返回下标
    //         }
    //     }
    //     return -1; // 未找到
    // }
};

