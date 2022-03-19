// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

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
    vector<int> vec;
    void preOrderTraversal(Node* root){

        if (!root) return;

        vec.push_back(root->val);
        for (int i=0; i<root->children.size(); i++){
             preOrderTraversal(root->children[i]);
        }
    }

    vector<int> preorder(Node* root) {

        preOrderTraversal(root);
        return vec;
    }
};