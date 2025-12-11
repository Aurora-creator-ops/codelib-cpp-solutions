//DFS-递归
class Solution {
private:
    int traversal(TreeNode*node){
        if(node==NULL)return 0;
        if(node->left==NULL && node->right==NULL)return 0;
        //左
        int lNum=traversal(node->left);
        if(node->left!=NULL && node->left->left==NULL && node->left->right==NULL)lNum=node->left->val;
        //右
        int rNum=traversal(node->right);
        //中
        int sum=lNum+rNum;
        return sum;
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        return traversal(root);
    }
};

//DFS-迭代-栈-前序
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;
        stack<TreeNode*>stk;
        stk.push(root);
        int sum=0;
        while(!stk.empty()){
            TreeNode*node=stk.top();stk.pop();

            if(node->left!=NULL && node->left->left==NULL && node->left->right==NULL)sum+=node->left->val;
            if(node->right)stk.push(node->right);
            if(node->left)stk.push(node->left);
            
        }
        return sum;
    }
};

//BFS-队列
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>que;
        que.push(root);
        int sum=0;
        while(!que.empty()){
            TreeNode*node=que.front();que.pop();

            if(node->left!=NULL && node->left->left==NULL && node->left->right==NULL)sum+=node->left->val;
            if(node->left)que.push(node->left);
            if(node->right)que.push(node->right);

        }
        return sum;
    }
};