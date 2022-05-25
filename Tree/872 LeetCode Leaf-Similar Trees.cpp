// Link: https://leetcode.com/problems/leaf-similar-trees/

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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        helper(root1, vec1);
        helper(root2, vec2);
        return (vec1 == vec2) ? true : false;
    }
private:
    vector<int> vec1, vec2;

    void helper(TreeNode* root, vector<int>& vec) {
        if (!root) return;

        helper(root->left, vec);
        helper(root->right, vec);

        if (!root->left && !root->right) vec.push_back(root->val);
    }
};