// Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/

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
    int minDepth(TreeNode* root) {
        helper(root, 1);
        return (result==INT_MAX) ? 0 : result;
    }
private:
    int result = INT_MAX;

    void helper(TreeNode* root, int depth) {
        if (!root) return;
        if (!root->left && !root->right) result = min(result, depth);
        helper(root->left, depth+1);
        helper(root->right, depth+1);
    }
};