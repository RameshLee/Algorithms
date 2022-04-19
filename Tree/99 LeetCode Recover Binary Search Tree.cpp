// Link: https://leetcode.com/problems/recover-binary-search-tree/

// T=O(N), S=O(1)
class Solution {
private: int flag = 0, prev = INT_MIN; TreeNode *A, *B;
public:
    void helper(TreeNode* root){ // find the first value out of order
        if (!root) return;

        helper(root->left);
        if (prev > root->val) A = root; prev = root->val;
        helper(root->right);
    }

    void helper2(TreeNode* root){ // find the swap position for that value
        if (!root) return;

        helper2(root->left);
        if (!flag && root->val > A->val) B = root, flag = 1;
        helper2(root->right);
    }

    void recoverTree(TreeNode* root) {

        // record the two nodes that need to be swapped
        helper(root);
        helper2(root);

        // swap the values
        int temp = A->val;
        A->val = B->val;
        B->val = temp;
    }
};