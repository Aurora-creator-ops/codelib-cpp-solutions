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
//leetcode 144
class Solution {
private:
    void traversal(TreeNode*root,vector<int>&result){
        if(root==NULL)return;
        result.push_back(root->val);
        traversal(root->left,result);
        traversal(root->right,result);
    }

public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int>result;
        traversal(root,result);
        return result;
    }
};
//leetcode 94
class Solution {
private:
    void traversal(TreeNode*root,vector<int>&result){
        if(root==NULL)return;
        traversal(root->left,result);
        result.push_back(root->val);
        traversal(root->right,result);
    }

public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>result;
        traversal(root,result);
        return result;
    }
};


//leetcode 145
class Solution {
private:
    void traversal(TreeNode*root,vector<int>&result){
        if(root==NULL)return;
        traversal(root->left,result);
        traversal(root->right,result);
        result.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>result;
        traversal(root,result);
        return result;
    }
};