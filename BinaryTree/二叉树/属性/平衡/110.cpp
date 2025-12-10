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

//递归：后序
class Solution {
private:
    int getHeight(TreeNode*root){
        if(root==NULL)return 0;
        //后序
        int leftHeight=getHeight(root->left);
        if(leftHeight==-1)return -1;
        int rightHeight=getHeight(root->right);
        if(rightHeight==-1)return -1;
        if(abs(rightHeight-leftHeight)>1)return -1;

        return 1+max(leftHeight,rightHeight);
    }

public:
    bool isBalanced(TreeNode* root) {
        int result=getHeight(root);
        if(result==-1)return false;
        return true;
    }
};
