// Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/

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
public:
    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    TreeNode* prev; int result = INT_MAX;

    void helper(TreeNode* root) { // inorder traversal of BST is a sorted array.
        if (!root) return;

        helper(root->left);
        if (!prev) prev = root;
        else {
            result = min(result, abs(root->val-prev->val));
            prev = root;
        }
        helper(root->right);
    }
};