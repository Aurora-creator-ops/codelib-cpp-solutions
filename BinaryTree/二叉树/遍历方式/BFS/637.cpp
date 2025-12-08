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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>result;
        queue<TreeNode*>que;
        if(root!=NULL)que.push(root);
        while(!que.empty()){
            int size=que.size();
            double sum=0.0;
            //while(size--){分母 size 的值被篡改
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();que.pop();
                if(node->left!=NULL)que.push(node->left);
                if(node->right!=NULL)que.push(node->right);
                sum+=node->val;
            }
            result.push_back(sum/size);
        }
        return result;
    }
};