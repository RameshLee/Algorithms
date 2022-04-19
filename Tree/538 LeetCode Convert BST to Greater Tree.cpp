// Link: https://leetcode.com/problems/convert-bst-to-greater-tree/

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
private:  vector<int> vec, suffixSum; int index=0; enum Action{READ, OVERWRITE};
public:
    void helper(TreeNode *root, int action){
        if (!root) return;
        helper(root->left, action);
        if (action == READ)         vec.push_back(root->val);
        if (action == OVERWRITE)    root->val = suffixSum[index++];
        helper(root->right, action);
    }

    TreeNode* bstToGst(TreeNode* root) {
        // Read: inorderTrav of BST is a sorted array
        helper(root, READ);

        // build suffixSum from the sorted array
        int n = vec.size(); suffixSum.resize(n+1, 0);
        for (auto i=n-1; i>=0; i--) suffixSum[i] = vec[i] + suffixSum[i+1];

        // Overwrite: inorderTraversal
        helper(root, OVERWRITE);
        return root;
    }
};