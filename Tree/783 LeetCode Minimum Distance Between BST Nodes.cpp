// Link: https://leetcode.com/problems/minimum-distance-between-bst-nodes/

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
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    TreeNode* prev; int result = INT_MAX;

    void helper(TreeNode* curr) { // inorderTraversal of BST is a sorted array.
        if (!curr) return;
        helper(curr->left);
        if (prev) result = min(result, abs(curr->val-prev->val));
        prev = curr;
        helper(curr->right);
    }
};