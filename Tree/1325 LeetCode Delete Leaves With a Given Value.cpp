// Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/

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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        helper(root, target);
        if (root && !root->left && !root->right) // corner-case
            return (root->val == target) ? nullptr : root;
        return root;
    }
private:
    void helper(TreeNode* root, int target) {
        if (!root) return;

        helper(root->left, target);
        helper(root->right, target);

        if (root->left && !root->left->left && !root->left->right) // left-leaf-node == target
            if (root->left->val == target)
                root->left = nullptr;

        if (root->right && !root->right->left && !root->right->right) // right-leaf-node == target
            if (root->right->val == target)
                root->right = nullptr;

    }
};