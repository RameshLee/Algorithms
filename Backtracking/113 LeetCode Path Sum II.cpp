// Link: https://leetcode.com/problems/path-sum-ii/

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
private: vector<vector<int>> ret; vector<int> vec; int pathsum = 0;
public:
    void helper(TreeNode* root, int &targetSum){
        if (!root) return;

        // make move
        vec.push_back(root->val);
        pathsum += root->val;;

        // recursively explore
        helper(root->left, targetSum);
        helper(root->right, targetSum);

        // check pathsum upon reaching leaf node
        if (!root->left && !root->right)
            if (pathsum == targetSum)
                ret.push_back(vec);

        // undo move
        vec.pop_back();
        pathsum -= root->val;
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root, targetSum);
        return ret;
    }
};