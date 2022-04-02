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

    void preOrderTraversal(Node* root, vector<int>& vec){

        if (!root) return;
        vec.push_back(root->val);
        for (auto it:root->children){
            preOrderTraversal(it,vec);
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> vec;
        preOrderTraversal(root, vec);
        return vec;
    }
};