// Link: https://leetcode.com/problems/maximum-average-subtree/

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
    double maximumAverageSubtree(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    double result = 0;

    vector<int> helper(TreeNode* root) {
        if (!root) return vector<int>();

        auto l = helper(root->left);
        auto r = helper(root->right);

        double sum = root->val;
        double n = 1 + l.size() + r.size();
        for (auto e:l) sum += (double)e;
        for (auto e:r) sum += (double)e;
        sum = sum/n;

        result = max(result, sum);

        vector<int> vec({root->val});
        vec.insert(vec.end(), l.begin(), l.end());
        vec.insert(vec.end(), r.begin(), r.end());
        return vec;
    }
};