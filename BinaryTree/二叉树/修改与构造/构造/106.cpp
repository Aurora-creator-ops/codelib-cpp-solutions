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
    TreeNode*traversal(vector<int>& inorder, vector<int>& postorder){
        if(postorder.size()==0)return NULL;

        int ret=postorder[postorder.size()-1];
        TreeNode*root=new TreeNode(ret);

        if(postorder.size()==1)return root;

        //找切割点
        int point;
        for(point=0;point<inorder.size();point++){
            if(inorder[point]==ret)break;
        }

        //切割中序数组
        vector<int>leftInorder(inorder.begin(),inorder.begin()+point);
        vector<int>rightInorder(inorder.begin()+point+1,inorder.end());

        postorder.resize(postorder.size()-1);

        //切割后序数组
        vector<int>leftPostorder(postorder.begin(),postorder.begin()+leftInorder.size());
        vector<int>rightPostOrder(postorder.begin()+leftInorder.size(),postorder.end());

        root->left=traversal(leftInorder,leftPostorder);
        root->right=traversal(rightInorder,rightPostOrder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0 || postorder.size()==0)return NULL;
        return traversal(inorder,postorder);
    }
};