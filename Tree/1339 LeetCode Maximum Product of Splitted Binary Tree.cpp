// Link: https://leetcode.com/problems/maximum-product-of-splitted-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */
class Solution {
public:
    int maxProduct(TreeNode* root) {
        auto total = traversal(root);
        subTreeSum(root, total);
        return std::fmod(result, pow(10,9)+7);
    }
private:
    double result = 0;

    double subTreeSum(TreeNode* root, double total) { // for each subtree, update result.
        if (!root) return 0;
        auto l = subTreeSum(root->left, total);
        auto r = subTreeSum(root->right, total);
        auto sum = root->val + l + r;
        result = max(result, sum * (total-sum)); // product of two subtrees
        return sum;
    }

    double traversal(TreeNode* root) { // find totalsum of the tree
        if (!root) return 0;
        auto l = traversal(root->left);
        auto r = traversal(root->right);
        return root->val+l+r;
    }
};