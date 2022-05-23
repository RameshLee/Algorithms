// Link: https://leetcode.com/problems/find-all-the-lonely-nodes/

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
    vector<int> getLonelyNodes(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    vector<int> result;

    TreeNode* helper(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* l = helper(root->left);
        TreeNode* r = helper(root->right);

        if (l && !r) result.push_back(l->val);
        if (!l && r) result.push_back(r->val);

        return root;
    }
};