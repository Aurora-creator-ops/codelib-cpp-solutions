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
    //后序
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;

        int leftHeight=maxDepth(root->left);
        int rightHeight=maxDepth(root->right);
        int Depth=1+max(leftHeight,rightHeight);

        return Depth;
    }
    //迭代：
    int maxDepth(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>que;
        que.push(root);
        int depth=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();que.pop();

                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
            depth++;
        }
        return depth;
    }
};