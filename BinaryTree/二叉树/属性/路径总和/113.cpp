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
//递归
class Solution {
vector<vector<int>>result;
vector<int>path;
private:
    void traversal(TreeNode* root, int count){
        if(root->left==NULL && root->right==NULL){
            if(count==0){
                result.push_back(path);
                return;
            }
            return;
        }

        if(root->left){
            count-=root->left->val;
            path.push_back(root->left->val);
            traversal(root->left,count);
            path.pop_back();
            count+=root->left->val;
        }
        if(root->right){
            count-=root->right->val;
            path.push_back(root->right->val);
            traversal(root->right,count);
            path.pop_back();
            count+=root->right->val;
        }

        return;
    }

public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return result;
        path.push_back(root->val);
        traversal(root,targetSum-root->val);
        return result;
    }
};