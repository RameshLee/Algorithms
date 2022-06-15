// Link: https://leetcode.com/problems/distribute-coins-in-binary-tree/

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

// Idea: return excess coins or required coins from each subtree to its root.
class Solution {
public:
    int distributeCoins(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    int result = 0;

    int helper(TreeNode* root) {
        if (!root) return 0;

        auto l = helper(root->left);
        auto r = helper(root->right);
        result += abs(l) + abs(r);
        return root->val+l+r-1;
    }
};