// Link: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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

// Approach: BFS
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result; vector<int> level;

        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) {
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                TreeNode* root = q.front(); q.pop();
                level.push_back(root->val);

                if (root->left) q.push(root->left);
                if (root->right) q.push(root->right);
            }
            result.push_back(level);
            level.clear();
        }
        std::reverse(result.begin(),result.end());
        return result;
    }
};