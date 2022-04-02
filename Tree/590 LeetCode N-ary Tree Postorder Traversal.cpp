// Link: https://leetcode.com/problems/n-ary-tree-postorder-traversal/

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
    void postOrderTraversal(Node* root, vector<int>& vec) {

        if (!root) return;
        for (auto it:root->children){
            postOrderTraversal(it, vec);
        }
        vec.push_back(root->val);

    }

    vector<int> postorder(Node* root) {
        vector<int> vec;
        postOrderTraversal(root,vec);
        return vec;
    }
};