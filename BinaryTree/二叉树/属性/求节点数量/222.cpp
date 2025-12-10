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
 //当做普通二叉树：递归
class Solution {
private:
    int getNum(TreeNode*root){
        if(root==NULL)return 0;
        //postOrder:
        int leftHeight=getNum(root->left);
        int rightHeight=getNum(root->right);
        int result=leftHeight+rightHeight+1;
        
        return result;
    }
public:
    int countNodes(TreeNode* root) {
        return getNum(root);
    }
};
 //当做普通二叉树：迭代
class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        queue<TreeNode*>que;
        que.push(root);
        int num=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode*node=que.front();que.pop();
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
                num++;
            }
        }
        return num;
    }
};
 //完全二叉树：递归
class Solution {
private:
    int getNum(TreeNode*root){
        //递归终止条件：1，节点为空；2，遇到了满二叉树
        if(root==NULL)return 0;

        int leftHeight=0,rightHeight=0;
        TreeNode*l=root->left;
        TreeNode*r=root->right;
        while(l){
            l=l->left;
            leftHeight++;
        }
        while(r){
            r=r->right;
            rightHeight++;
        }
        if(leftHeight==rightHeight)return (2<<leftHeight)-1;

        //后序
        int leftNum=getNum(root->left);
        int rightNum=getNum(root->right);
        int result=1+leftNum+rightNum;

        return result;
    }
public:
    int countNodes(TreeNode* root) {
        return getNum(root);
    }
};