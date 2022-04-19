// Link: https://leetcode.com/problems/validate-binary-search-tree/

// Inorder traversal of BST is a sorted array: T=O(N), S=O(1)

class Solution {
private: int k, index=0, result=0;
public:
    void helper(TreeNode* root){
        if (!root) return;
        if (result) return;

        helper(root->left);
        if (++index == k) result = root->val;
        helper(root->right);
    }

    int kthSmallest(TreeNode* root, int _k) {
        k = _k;
        helper(root);
        return result;
    }
};