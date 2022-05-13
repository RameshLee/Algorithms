// Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/

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
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    int result = 0;

    TreeNode* helper(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* l = helper(root->left);
        TreeNode* r = helper(root->right);

        if (root->val % 2 == 0) { // if grandparent is even, then add their grandchildren!
            if (l && l->left)   result += l->left->val;
            if (l && l->right)  result += l->right->val;
            if (r && r->left)   result += r->left->val;
            if (r && r->right)  result += r->right->val;
        }
        return root;
    }
};