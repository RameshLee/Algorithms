// Link: https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
private: int globalMax=INT_MIN;
public:
    int helper(TreeNode* root){
        if (!root) return 0;

        int A = max(helper(root->left), 0); // trick is to ignore the negative elements
        int B = max(helper(root->right), 0);
        int C = root->val;
        int D = A+B+C;

        globalMax = max(globalMax, D);

        return C+max(A,B);
    }

    int maxPathSum(TreeNode* root) {
        int k = helper(root);
        return globalMax;
    }
};

