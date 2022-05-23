// Link: https://leetcode.com/problems/univalued-binary-tree/

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
    bool isUnivalTree(TreeNode* root) {
        unordered_set<int> Set;
        helper(root, Set);
        return (Set.size()>1) ? false : true;
    }
private:
    void helper(TreeNode* root, unordered_set<int>& Set) {
        if (!root) return;
        helper(root->left, Set);
        helper(root->right, Set);
        Set.insert(root->val);
    }
};