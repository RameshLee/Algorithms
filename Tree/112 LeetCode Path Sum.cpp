// Link: https://leetcode.com/problems/path-sum/

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
    int sum = 0; bool output = false;

    bool hasPathSum(TreeNode* root, int targetSum) {

        if (!root) return false;

        sum += root->val;

        hasPathSum(root->left, targetSum);
        hasPathSum(root->right, targetSum);

        if (!root->left && !root->right)
            if (sum == targetSum)
                output = true;

        sum -= root->val;

        return output;
    }
};