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
int maxDepth=INT_MIN;
int result;
private:
    void traversal(TreeNode*root,int depth){
        //终止条件
        if(root->left==NULL && root->right==NULL){
            if(depth>maxDepth){
                maxDepth=depth;
                result=root->val;
            }
            return;
        }
        //中为空，所以前中后序都可以，而且代码一样
        //左
        if(root->left){
            depth++;
            traversal(root->left,depth);
            depth--;
        }
        //右
        if(root->right){
            depth++;
            traversal(root->right,depth);
            depth--;
        }
        return;
    }
public:
    int findBottomLeftValue(TreeNode* root) {
        traversal(root,0);
        return result;
    }
};
//迭代
class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ret;
        if(root==NULL)return 0;
        queue<TreeNode*>que;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            ret=que.front()->val;
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();que.pop();
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return ret;
    }
};