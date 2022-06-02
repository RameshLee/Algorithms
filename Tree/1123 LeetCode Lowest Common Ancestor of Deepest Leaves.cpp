// Link: https://leetcode.com/problems/lowest-common-ancestor-of-deepest-leaves/

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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findDeepestLeaves(root); // find deepest leaves using bfs
        lowestCommonAncestor(root, Leaves); // find the lowestCommonAncestor
        return LCA;
    }
private:
    void findDeepestLeaves(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) { // bfs/level-order-traversal
            int sz = q.size(); Leaves.clear();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                Leaves.push_back(curr);
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
        }
    }

private:
    int lowestCommonAncestor(TreeNode* root, vector<TreeNode*>& Leaves) {
        if (!root) return 0;

        auto l = lowestCommonAncestor(root->left, Leaves);
        auto r = lowestCommonAncestor(root->right, Leaves);
        auto curr = 0;
        for (auto n : Leaves) {
            curr = (root->val == n->val) ? 1 : 0;
            if (curr) break;
        }

        if (l+r+curr >= Leaves.size() && !LCA) LCA = root; // record LCA

        return (l+r+curr);
    }
private:
    TreeNode* LCA; vector<TreeNode*> Leaves;
};