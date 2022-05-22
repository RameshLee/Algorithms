// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree-iv/

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
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        this->n = nodes.size();
        helper(root, nodes);
        return LCA;
    }
private:
    TreeNode* LCA = nullptr; int n;

    int helper(TreeNode* root, vector<TreeNode*> &nodes) {
        if (!root) return 0;

        int l = helper(root->left, nodes);  // left-subtree has l number of candidate.
        int r = helper(root->right, nodes); // right-subtree has r number of candidate.
        int curr = 0;                // current node has one candidate.
        for (auto n:nodes) {
            curr = (root->val==n->val) ? 1 : 0;
            if (curr) break;
        }

        if (l+r+curr >= n && !LCA) { // LCA-found
            LCA = root;
        }
        return (l+curr+r);
    }
};