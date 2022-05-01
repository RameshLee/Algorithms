// Link: https://leetcode.com/problems/delete-node-in-a-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {

        if (!root) return nullptr;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        }
        else if (key == root->val) { // node that needs to be deleted
            // three cases
            if (!root->left && !root->right) { // no child
                root = nullptr;
            }
            else if (root->left) { // left child
                root->val = predecessor(root);
                root->left = deleteNode(root->left, root->val);
            }
            else if (root->right) { // right child
                root->val = successor(root);
                root->right = deleteNode(root->right, root->val);
            }
        }
        return root;
    }
private:
    int successor(TreeNode* root){ // next value in the sorted array
        root = root->right;
        while (root->left) root = root->left;
        return root->val;
    }

    int predecessor(TreeNode* root){ // prev value in the sorted array
        root = root->left;
        while (root->right) root = root->right;
        return root->val;
    }
};