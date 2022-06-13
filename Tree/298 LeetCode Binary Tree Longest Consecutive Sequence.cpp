// Link: https://leetcode.com/problems/binary-tree-longest-consecutive-sequence/

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
    int longestConsecutive(TreeNode* root) {
        helper(root, -99, 1);
        return result;
    }
private:
    int result = 1;

    void helper(TreeNode* root, int prev, int length) {
        if (!root) return;

        if (root->val - prev == 1) { // valid increasing sequence
            result = max(result, 1+length);
            helper(root->left, root->val, 1+length);
            helper(root->right, root->val, 1+length);
        }
        else { // sequence restarts
            helper(root->left, root->val, 1);
            helper(root->right, root->val, 1);
        }
    }
};