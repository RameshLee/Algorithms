// Link: https://leetcode.com/problems/sum-of-left-leaves/

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
    void helper(TreeNode* root, int l, int &sum) {

        if (!root) return;
        if (l && !root->left && !root->right) sum += root->val;
        helper(root->left, 1, sum);
        helper(root->right, 0, sum);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        helper(root,0,sum);
        return sum;
    }
};