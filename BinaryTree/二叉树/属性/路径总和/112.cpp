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

 
//递归：
class Solution {
private:
    bool traversal(TreeNode*root,int count){
        if(root->left==NULL && root->right==NULL){
            if(count==0)return true;
            return false;
        }
        //左
        if(root->left){
            count-=root->left->val;
            if(traversal(root->left,count))return true;
            count+=root->left->val;
        }
        //右
        if(root->right){
            count-=root->right->val;
            if(traversal(root->right,count))return true;
            count+=root->right->val;
        }

        return false;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return false;
        return traversal(root,targetSum-root->val);
    }
};