// Link: https://leetcode.com/problems/find-leaves-of-binary-tree/

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

// 1) dfs: find the pairs of heights and node values; update result. T=O(N), S=O(N)
// Record node values at all heights using hashmap

class Solution {
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        // get the pair of heights and node values
        helper(root);
        vector<vector<int>> result((int)Map.size(), vector<int>());
        for (auto it:Map) result[it.first] = it.second;
        return result;
    }
private:
    unordered_map<int,vector<int>> Map; //height,{values}

    int helper(TreeNode* root) {
        if (!root) return -1;
        auto currHeight = 1 + max( helper(root->left), helper(root->right) );
        Map[currHeight].push_back(root->val);
        return currHeight;
    }
};