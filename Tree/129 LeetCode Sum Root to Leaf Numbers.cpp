// Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
private: int sum = 0; string s;
public:
    void helper(TreeNode* root) {
        if (!root) return;

        s += to_string(root->val);
        helper(root->left);
        helper(root->right);

        if (!root->left && !root->right) sum += stoi(s);
        s.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        helper(root);
        return sum;
    }
};