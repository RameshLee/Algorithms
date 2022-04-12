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
private: using vi = vector<long>; vi vec; int count = 0;
public:
    vi helper(TreeNode* root, int &targetSum){
        if (!root) return vi();

        vi left = helper(root->left, targetSum);
        vi right = helper(root->right, targetSum);

        vi vec; vec.push_back(root->val);
        for (auto& ele:left) vec.push_back(root->val + ele);
        for (auto& ele:right) vec.push_back(root->val + ele);
        for (auto& ele:vec) if (ele == targetSum) count++;

        return vec;
    }

    int pathSum(TreeNode* root, int targetSum) {
        vi vec = helper(root, targetSum);
        return count;
    }
};