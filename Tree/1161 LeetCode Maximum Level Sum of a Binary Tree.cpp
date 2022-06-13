// Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    int maxLevelSum(TreeNode* root) {
        int maxLevel = 0, maxSum = INT_MIN;
        queue<TreeNode*> q; q.push(root);
        for (auto level=1; !q.empty(); level++) { // bfs/level-order-traversal
            int sz = q.size(), sum = 0;
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                sum += curr->val;
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            if (maxSum < sum) maxSum = sum, maxLevel = level; // update output
        }
        return maxLevel;
    }
};