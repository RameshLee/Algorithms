// Link: https://leetcode.com/problems/find-distance-in-a-binary-tree/

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
    int findDistance(TreeNode* root, int p, int q) {
        lowestCommonAncestor(root,p,q);  // find LCA of p & q
        temp = 0, computeDist(LCA,p,0), leftHeight = temp; // find dist from LCA to p
        temp = 0, computeDist(LCA,q,0), rightHeight = temp; // find dist from LCA to q
        return leftHeight + rightHeight; // return total distance
    }
private:
    TreeNode* LCA; int leftHeight, rightHeight, temp;

    int lowestCommonAncestor(TreeNode* root, int p, int q) { // find LCA of p & q
        if (!root) return 0;

        int l = lowestCommonAncestor(root->left,p,q);
        int r = lowestCommonAncestor(root->right,p,q);
        int curr = (root->val == p || root->val == q) ? 1 : 0;

        if (l+r+curr >= 2) LCA = root;

        return (l || r || curr) ? 1 : 0;
    }

    void computeDist(TreeNode* root, int val, int depth) { // find height from LCA to given node
        if (!root) return;
        if (root->val == val) temp = depth;
        computeDist(root->left, val, depth+1);
        computeDist(root->right, val, depth+1);
    }
};