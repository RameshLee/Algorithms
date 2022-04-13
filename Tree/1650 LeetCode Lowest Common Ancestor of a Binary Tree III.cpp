// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
private: Node* LCA = nullptr;
public:
    int helper(Node* root, Node* p, Node* q) {
        if (!root) return 0;

        int l = helper(root->left,p,q);
        int r = helper(root->right,p,q);
        int curr = (root->val == p->val || root->val == q->val) ? 1 : 0;

        if (l+r+curr >= 2) LCA = root;

        if (curr || l || r) return 1;
        return 0;
    }
    Node* lowestCommonAncestor(Node* p, Node * q) {
        Node *root;
        root = p;
        while (root->parent) root = root->parent;
        helper(root,p,q);
        return LCA;
    }
};