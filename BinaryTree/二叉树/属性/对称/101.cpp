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


//递归：后序
class Solution {
private:
    bool isSame(TreeNode*l,TreeNode*r){
        if(l==NULL && r!=NULL)return false;
        else if(l!=NULL && r==NULL)return false;
        else if(l==NULL && r==NULL)return true;
        else if(l->val!=r->val)return false;
        
        bool outside=isSame(l->left,r->right);
        bool inside=isSame(l->right,r->left);

        bool result=outside && inside;

        return result;
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        return isSame(root->left,root->right);
    }
};

//迭代：层序遍历
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root==NULL)return true;
        queue<TreeNode*>que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode*l=que.front();que.pop();
            TreeNode*r=que.front();que.pop();

            if(l==NULL && r!=NULL)return false;
            else if(l!=NULL && r==NULL)return false;
            else if(l==NULL && r==NULL)continue;//这里不是直接返回true，之前递归虽然这么写，但其实不一定到了最后返回结果
            else if(l->val!=r->val)return false;

            que.push(l->left);
            que.push(r->right);
            que.push(l->right);
            que.push(r->left);
        }
        return true;
    }
};