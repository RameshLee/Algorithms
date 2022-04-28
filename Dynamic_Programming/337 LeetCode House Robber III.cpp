// Link: https://leetcode.com/problems/house-robber-iii/

// Concept: compute gain at each node for these conditions: 1) if that node is robbed, 2) if that node is not robbed.

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
    int rob(TreeNode* root) {
        vector<int> ret = helper(root);
        return max(ret[0],ret[1]);
    }
private:
    vector<int> helper(TreeNode* root){
        if (!root){
            return vector<int>({0,0});
        }

        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);

        int robbed = root->val + l[1] + r[1];
        int notRobbed = max(l[0],l[1]) + max(r[0],r[1]);

        return vector<int>({robbed,notRobbed});
    }

};