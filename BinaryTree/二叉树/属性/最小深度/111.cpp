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
    int getHeight(TreeNode*root){
        if(root==NULL)return 0;
        //后序
        int leftHeight=getHeight(root->left);
        int rightHeight=getHeight(root->right);
        if(root->left==NULL && root->right!=NULL){
            return 1+rightHeight;
        }else if(root->left!=NULL && root->right==NULL){
            return 1+leftHeight;
        }else{
            return 1+min(leftHeight,rightHeight);
        }
    }
public:
    int minDepth(TreeNode* root) {
        return getHeight(root);
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>que;
        que.push(root);
        int depth=0;
        while(!que.empty()){
            int size=que.size();
            depth++;
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();
                que.pop();
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
                if(node->left==NULL && node->right==NULL)return depth;
            }
        }
        return depth;
    }
};