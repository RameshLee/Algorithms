// Link: https://leetcode.com/problems/inorder-successor-in-bst/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* prev;
    TreeNode* result;

    void InOrderTraversal(TreeNode* root, TreeNode* p){

        if (!root) return;
        if (result) return;

        InOrderTraversal(root->left, p);
        if (prev == p) result = root;
        prev = root;
        InOrderTraversal(root->right, p);
    }

    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {

        InOrderTraversal(root,p);
        return result;
    }
};