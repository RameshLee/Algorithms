// Link: https://leetcode.com/problems/subtree-of-another-tree/

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
// 1) recursive approach (brute force)
class Solution {
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        helper(root,subRoot);
        return result;
    }
private:
    bool result = false;

    void helper(TreeNode* root, TreeNode* subRoot) {
        if (!root) return;
        if (!result) result = isSameTree(root, subRoot);

        helper(root->left, subRoot);
        helper(root->right, subRoot);
    }

    bool isSameTree(TreeNode* A, TreeNode* B) {
        if (!A && !B) return true;
        if (!A || !B) return false;

        bool curr = (A->val == B->val) ? true : false;
        return (curr && isSameTree(A->left,B->left) && isSameTree(A->right, B->right));
    }
};