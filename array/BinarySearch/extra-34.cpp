class Solution {
private:
    // 获取左边界（小于target的最后一个元素下标，初始值-2表示未有效查找）
    int getLeftBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
                leftBorder = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return leftBorder;
    }

    // 获取右边界（大于target的第一个元素下标，初始值-2表示未有效查找）
    int getRightBorder(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int rightBorder = -2;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] > target) {
                right = middle - 1;
            } else {
                left = middle + 1;
                rightBorder = middle + 1;
            }
        }
        return rightBorder;
    }
public:
    // 查找target在数组中的起始和结束下标，不存在则返回[-1,-1]
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftBorder = getLeftBorder(nums, target);
        int rightBorder = getRightBorder(nums, target);

        // 情况1：未找到有效边界（target不在数组中或数组为空）
        if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
        // 情况2：找到边界，计算实际起始和结束下标
        if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
        // 情况3：边界无效（target不在数组中）
        return {-1, -1};
    }
};
