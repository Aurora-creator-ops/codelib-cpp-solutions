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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>result;
        queue<TreeNode*>que;
        if(root!=NULL)que.push(root);
        while(!que.empty()){
            int lastVal=0;
            int size=que.size();
            vector<int>vec;
            while(size--){
                TreeNode*node=que.front();que.pop();
                if(node->left!=NULL)que.push(node->left);
                if(node->right!=NULL)que.push(node->right);
                vec.push_back(node->val);
                lastVal=node->val;//不断更新，最后就是当前层最后一个值
            }
            //result.push_back(vec.end());不能这么写
            //vec.end() 返回的是迭代器（指向 vector 末尾的位置），而 result 是存储 int 类型的 vector，无法直接将迭代器推入，类型不匹配。
            result.push_back(lastVal);
        }
        return result;
    }
};