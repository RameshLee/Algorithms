// Link: https://leetcode.com/problems/maximum-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return helper(0,nums.size()-1,nums);
    }
private:
    TreeNode* helper(int start, int end, vector<int>& nums) {
        if (start>end) {
            return nullptr;
        }

        auto pi = findMax(start,end,nums);
        auto val = pi.first, index = pi.second;
        TreeNode* root = new TreeNode(val);
        root->right = helper(index+1, end, nums);
        root->left = helper(start, index-1, nums);

        return root;
    }

    pair<int,int> findMax(int start, int end, vector<int>& nums) {
        pair<int,int> pi;
        pi = make_pair(nums[start], start);
        for (int i=start+1; i<=end; i++) {
            if (pi.first < nums[i])
                pi = make_pair(nums[i],i);
        }
        return pi;
    }
};