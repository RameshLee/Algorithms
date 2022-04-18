// Link: https://leetcode.com/problems/range-sum-of-bst/

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
private: int low, high, sum = 0;
public:
    void helper(TreeNode* root) {
        if (!root) return;
        if (low <= root->val && root->val <= high) sum += root->val;
        helper(root->left);
        helper(root->right);
    }
    int rangeSumBST(TreeNode* root, int _low, int _high) {
        low = _low, high = _high;
        helper(root);
        return sum;
    }
};