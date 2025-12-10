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

//DFS，递归：前序
class Solution {
private:
    void traversal(TreeNode*node,vector<int>&path,vector<string>&result){
        //中：
        path.push_back(node->val);
        //递归终止条件：
        if(node->left==NULL && node->right==NULL){
            string s;
            for(int i=0;i<path.size()-1;i++){
                s+=to_string(path[i]);//不能用s.push_back(to_char)，因为有可能是12，不是一个字符
                s+="->";
            }
            s+=to_string(path[path.size()-1]);
            result.push_back(s);
            return;
        }
        //左
        if(node->left){
            traversal(node->left,path,result);
            //回溯
            path.pop_back();
        }
        //右
        if(node->right){
            traversal(node->right,path,result);
            //回溯
            path.pop_back();
        }
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        vector<int>path;
        if(root==NULL)return result;
        traversal(root,path,result);
        return result;
    }
};
//DFS-迭代：栈
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        stack<TreeNode*>tree;
        stack<string>path;
        if(root==NULL)return result;
        tree.push(root);
        path.push(to_string(root->val));
        while(!tree.empty()){
            TreeNode*node=tree.top();tree.pop();//中
            string p=path.top();path.pop();
            if(node->left==NULL && node->right==NULL){
                result.push_back(p);
            }
            //右
            if(node->right){
                tree.push(node->right);
                path.push(p+"->"+to_string(node->right->val));
            }
            //左
            if(node->left){
                tree.push(node->left);
                path.push(p+"->"+to_string(node->left->val));
            }
        }
        return result;
    }
};
//BFS-迭代：队列
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>result;
        queue<TreeNode*>tree;
        queue<string>path;

        if(root==NULL)return result;

        tree.push(root);
        path.push(to_string(root->val));

        while(!tree.empty()){
            TreeNode*node=tree.front();tree.pop();//中
            string p=path.front();path.pop();
            if(node->left==NULL && node->right==NULL){
                result.push_back(p);
            }
            //左
            if(node->left){
                tree.push(node->left);
                path.push(p+"->"+to_string(node->left->val));
            }

            //右
            if(node->right){
                tree.push(node->right);
                path.push(p+"->"+to_string(node->right->val));
            }
            
        }
        return result;
    }
};