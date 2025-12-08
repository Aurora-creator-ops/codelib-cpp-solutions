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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>>result;
        queue<TreeNode*>que;
        if(root!=NULL)que.push(root);
        while(!que.empty()){
            int size=que.size();
            vector<int>vec;
            while(size--){
                TreeNode*node=que.front();que.pop();
                //也可以在这里直接找每层的最大值： maxVal = max(maxVal, node->val);
                if(node->left!=NULL)que.push(node->left);
                if(node->right!=NULL)que.push(node->right);
                vec.push_back(node->val);
            }
            result.push_back(vec);
        }
        vector<int>res;
        for(int i=0;i<result.size();i++){
            int maxVal=INT_MIN;//有负数，初始化为int最小值
            for(int j=0;j<result[i].size();j++){//不是result[0].size，每层数量不相同
                if(result[i][j]>maxVal)maxVal=result[i][j];
            }
            res.push_back(maxVal);
        }

        return res;
    }
};