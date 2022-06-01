// Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    int goodNodes(TreeNode* root) {
        helper(root);
        return count;
    }
private:
    int greatestSoFar = INT_MIN, count = 0;

    void helper(TreeNode* root) {
        if (!root) return; // base-case
        if (greatestSoFar <= root->val) count++; // update output

        auto backup = greatestSoFar;
        greatestSoFar = max(greatestSoFar, root->val); // make-move

        helper(root->left); // explore candidates
        helper(root->right);

        // undo-move
        greatestSoFar = backup; // undo-move
    }
};