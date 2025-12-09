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
    bool isSame(TreeNode*p,TreeNode*q){
        if(p==NULL && q!=NULL)return false;
        else if(p!=NULL && q==NULL)return false;
        else if(p==NULL && q==NULL)return true;
        else if(p->val!=q->val)return false;

        bool l=isSame(p->left,q->left);
        bool r=isSame(p->right,q->right);
        bool result=l && r;

        return result;
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot!=NULL)return false;
        else if(root!=NULL && subRoot==NULL)return false;
        else if(root==NULL && subRoot==NULL)return true;


        if(isSame(root,subRoot))return true;
        else{
            bool l=isSubtree(root->left,subRoot);
            bool r=isSubtree(root->right,subRoot);
            return l || r;
        }
    }
};