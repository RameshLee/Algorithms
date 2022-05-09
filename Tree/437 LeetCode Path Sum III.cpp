// Link: https://leetcode.com/problems/path-sum-iii/

// One-pass linear algorithm: O(N) recursive solution

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
public: int pathSum(TreeNode* root, int targetSum) {
        this->targetSum = targetSum;
        helper(root);
        return count;
    }

private:
    vector<long> vec; int targetSum, count = 0;

    vector<long> helper(TreeNode* root){
        if (!root) return vector<long>();

        vector<long> left  = helper(root->left);
        vector<long> right = helper(root->right);

        vector<long> vec = {root->val};
        for (auto i:left) vec.push_back(root->val + i);
        for (auto i:right) vec.push_back(root->val + i);
        for (auto i:vec) if (i == targetSum) count++;

        return vec;
    }
};