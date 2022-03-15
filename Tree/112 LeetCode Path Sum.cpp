// Link: https://leetcode.com/problems/path-sum/

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
    int height = 0;
    bool output = false;
    bool hasPathSum(TreeNode* root, int targetSum) {

        if (root == NULL) return false;

        height += root->val;

        hasPathSum(root->left, targetSum);
        hasPathSum(root->right, targetSum);

        if (root->left==NULL && root->right==NULL)
            if (height == targetSum)
                output = true;

        height -= root->val;

        return output;
    }
};