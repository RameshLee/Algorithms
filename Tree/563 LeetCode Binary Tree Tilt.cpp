// Link: https://leetcode.com/problems/binary-tree-tilt/

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
    int findTilt(TreeNode* root) {
        int sum = 0;
        helper(root, sum);
        return sum;
    }
private:
    int helper(TreeNode* root, int &sum) {
        if (!root) return 0;

        auto l = helper(root->left, sum);
        auto r = helper(root->right, sum);
        auto val = root->val;
        root->val = abs(l-r);
        sum += root->val;

        return val+l+r;
    }
};