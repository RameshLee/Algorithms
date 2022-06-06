// Link: https://leetcode.com/problems/maximum-difference-between-node-and-ancestor/

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
    int maxAncestorDiff(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    int result = 0;

    vector<int> helper(TreeNode* root) {
        if (!root) return vector<int>();

        auto l = helper(root->left);
        auto r = helper(root->right);

        for (auto e:l) result = max(result, abs(e-root->val));
        for (auto e:r) result = max(result, abs(e-root->val));

        // keep track of only min & max elements of each subtree
        vector<int> vec;
        auto Min = root->val, Max = root->val;
        for (auto e:l) Min = min(Min, e), Max = max(Max, e);
        for (auto e:r) Min = min(Min, e), Max = max(Max, e);

        return vector<int>({Min,Max});
    }
};