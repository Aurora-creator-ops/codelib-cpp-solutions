class Solution {
private:
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder){
        if(preorder.size()==0)return NULL;

        int ret=preorder[0];
        TreeNode*root=new TreeNode(ret);

        if(preorder.size()==1)return root;

        //找切割点
        int point;
        for(point=0;point<inorder.size();point++){
            if(inorder[point]==ret)break;
        }

        //切割中序数组
        vector<int>leftInorder(inorder.begin(),inorder.begin()+point);
        vector<int>rightInorder(inorder.begin()+point+1,inorder.end());


        //切割前序数组
        vector<int>leftPreorder(preorder.begin()+1,preorder.begin()+1+leftInorder.size());
        vector<int>rightPreorder(preorder.begin()+1+leftInorder.size(),preorder.end());

        root->left=traversal(leftPreorder,leftInorder);
        root->right=traversal(rightPreorder,rightInorder);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 || inorder.size()==0)return NULL;
        return traversal(preorder,inorder);
    }
};