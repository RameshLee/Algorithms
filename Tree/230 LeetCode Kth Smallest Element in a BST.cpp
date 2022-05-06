// Link: https://leetcode.com/problems/validate-binary-search-tree/

// Inorder traversal of BST is a sorted array: T=O(N), S=O(1)

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        this->k = k;
        helper(root);
        return result;
    }
private:
    int k, index=0, result=0;

    void helper(TreeNode* root){
        if (!root || result) return;

        helper(root->left);
        if (++index == k) result = root->val;
        helper(root->right);
    }
};