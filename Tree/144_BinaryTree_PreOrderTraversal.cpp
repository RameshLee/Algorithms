// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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
    vector<int> vec;
    void helper(TreeNode* root)
    {
        if (root != NULL)
        {
            vec.push_back(root->val);
            helper(root->left);
            helper(root->right);
        }
    }
    vector<int> preorderTraversal(TreeNode* root)
    {
        helper(root);
        return vec;
    }
};