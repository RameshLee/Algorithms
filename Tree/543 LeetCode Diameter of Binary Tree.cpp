// Link: https://leetcode.com/problems/diameter-of-binary-tree/

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

// 1) one-pass solution: T=O(N), S=O(1)

// find diameter of all nodes and return the max diameter
// diameter of any node is the sum of max heights of their left & right subtree

class Solution{
public:
    int diameterOfBinaryTree(TreeNode* root) {
        helper(root);
        return maxDiameter;
    }
private:
    int maxDiameter = 0;
    int helper(TreeNode* root){
        if (!root) return 0;
        int l = helper(root->left); // height of left subtree
        int r = helper(root->right); // height of right subtree
        maxDiameter = max(maxDiameter, l+r); // record diameter
        return max(l,r)+1; // return height of largest subtree plus one
    }
};


// 2) brute force: T=O(N^p), S=O(1)

// Algo:
// 1) make an inorder traversal to go through all nodes
// 2) for each node, find the max height of left & right subtrees to calculate the diameter.
// 3) return the globalMax diameter.

/*
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
};*/