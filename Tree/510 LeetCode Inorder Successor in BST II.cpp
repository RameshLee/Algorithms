// Link: https://leetcode.com/problems/inorder-successor-in-bst-ii/

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
public:
    Node* inorderSuccessor(Node* node) {
        target = node;

        // find the root node
        Node* root = node;
        while (root->parent) root = root->parent;

        // inorder traversal
        helper(root);
        return successor;
    }
private:
    Node *successor = nullptr, *prev, *target;

    void helper(Node* root) {
        if (!root) return;

        helper(root->left);
        if (prev == target) successor = root;
        prev = root;
        helper(root->right);
    }
};