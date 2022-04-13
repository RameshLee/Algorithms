// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-ii/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private: TreeNode* LCA = nullptr;
public:
    int helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return 0;

        int l = helper(root->left,p,q);
        int r = helper(root->right,p,q);
        int curr = (root->val == p->val || root->val == q->val) ? 1 : 0;

        if (l+r+curr >= 2) LCA = root;

        if (curr || l || r) return 1;
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        helper(root,p,q);
        return LCA;
    }
};