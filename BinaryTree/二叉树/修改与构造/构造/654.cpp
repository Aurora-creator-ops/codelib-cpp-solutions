/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode*root=new TreeNode(nums[0]);
        if(nums.size()==1)return root;

        //找最大值和下标
        int maxNum=-1;
        int maxIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxNum){
                maxNum=nums[i];
                maxIndex=i;
            }
        }
        root->val=maxNum;

        //划分
        if(maxIndex>0){
            vector<int>leftNum(nums.begin(),nums.begin()+maxIndex);
            root->left=constructMaximumBinaryTree(leftNum);
        }
        if(maxIndex<nums.size()-1){
            vector<int>rightNum(nums.begin()+maxIndex+1,nums.end());
            root->right=constructMaximumBinaryTree(rightNum);
        }
        
        return root;
    }
};