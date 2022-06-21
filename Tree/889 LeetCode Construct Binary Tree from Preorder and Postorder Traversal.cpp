// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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

// Idea: increase preorder index until preorderVal == postorderVal, which means a subtree is built.
class Solution {
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        TreeNode* root = new TreeNode(preorder[i++]);
        if (root->val != postorder[j]) root->left = constructFromPrePost(preorder, postorder);
        if (root->val != postorder[j]) root->right = constructFromPrePost(preorder, postorder);
        j++;
        return root;
    }
private:
    int i = 0, j = 0;
};