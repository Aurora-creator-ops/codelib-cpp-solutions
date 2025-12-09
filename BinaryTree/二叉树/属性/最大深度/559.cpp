/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    //递归:后序
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        int depth=0;
        for(int i=0;i<root->children.size();i++){
            int childrenHeight=maxDepth(root->children[i]);
            depth=max(depth,childrenHeight);
        }
        return depth+1;
    }
    //迭代
    int maxDepth(Node* root) {
        if(root==NULL)return 0;
        queue<Node*>que;
        que.push(root);
        int depth=0;
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                Node*node=que.front();que.pop();
                for(int j=0;j<node->children.size();j++){
                    if(node->children[j])que.push(node->children[j]);
                }
            }
            depth++;
        }
        return depth;
    }
};