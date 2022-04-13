// Link: https://leetcode.com/problems/diameter-of-binary-tree/

// Algo:
// 1) make an inorder traversal to go through all nodes
// 2) for each node, find the max height of left & right subtrees to calculate the diameter.
// 3) return the globalMax diameter.

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
    int globalMax = INT_MIN;

    int helper(TreeNode* root) {
        if (!root) return 0;
        return max(1+helper(root->left), 1+helper(root->right));
    }

    void dfs(TreeNode* root){

        if (!root) return;

        // calculate the summation of max tree height for left & right subtree of all nodes
        int l = helper(root->left);
        int r = helper(root->right);

        globalMax = max(globalMax, l+r);

        dfs(root->left);
        dfs(root->right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return globalMax;
    }
};