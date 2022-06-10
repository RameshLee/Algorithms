// Link: https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

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
    int pseudoPalindromicPaths (TreeNode* root) {
        values.resize(10,0);
        helper(root);
        return result;
    }
private:
    vector<int> values;
    int result = 0;

    void helper(TreeNode* root) {
        if (!root) return;

        values[root->val]++; // make move

        if (!root->left && !root->right) { // update result
            int count = 0; for (auto e:values) if (e%2 != 0) count++;
            if (count <= 1) result++;
        }

        helper(root->left); // recursively explore
        helper(root->right);

        values[root->val]--; // undo move
    }
};