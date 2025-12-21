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
private:
    TreeNode* recursion(TreeNode*root,int val){
        if(root==NULL || root->val==val)return root;
        if(root->val>val) return recursion(root->left,val);
        if(root->val<val)return recursion(root->right,val);
        return NULL;
    }

    TreeNode*iteration(TreeNode*root,int val){
        if(root==NULL || root->val==val)return root;
        while(root){
            if(root->val>val)root=root->left;
            else if(root->val<val)root=root->right;
            else return root;
        }
        return root;
    }

public:
    TreeNode* searchBST(TreeNode* root, int val) {
        //return recursion(root,val);//二选一：递归，迭代
        return iteration(root,val);
    }
};