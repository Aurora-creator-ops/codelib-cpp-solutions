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
    //DFS-递归前序
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    //DFS-递归后序
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left,root->right);
        return root;
    }
    //DFS-迭代前序
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            //中
            TreeNode*node=stk.top();
            stk.pop();
            //翻转
            swap(node->left,node->right);
            //右
            if(node->right)stk.push(node->right);
            //左
            if(node->left)stk.push(node->left);
        }
        return root;
    }
    //DFS-迭代后序
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        stack<TreeNode*>stk;
        stk.push(root);
        while(!stk.empty()){
            TreeNode*node=stk.top();
            stk.pop();
            swap(node->left,node->right);
            if(node->left)stk.push(node->left);
            if(node->right)stk.push(node->right);
        }
        return root;
    }
    //BFS
    TreeNode* invertTree(TreeNode* root) {
        if(root==NULL)return root;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();
                que.pop();
                swap(node->left,node->right);
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return root;
    }
};