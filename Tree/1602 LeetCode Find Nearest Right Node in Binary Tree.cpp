// Link: https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/

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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        queue<pair<TreeNode*,int>> q;
        if (root) q.push(make_pair(root,0));
        while (!q.empty()) { // level-order traversal
            for (auto loop=0; loop<q.size(); loop++) {
                auto curr = q.front().first;
                auto level = q.front().second; q.pop();
                if (curr == u) { // check the next val in the queue
                    return (!q.empty() && q.front().second==level) ? q.front().first : nullptr;
                }
                if (curr->left) q.push(make_pair(curr->left, level+1));
                if (curr->right) q.push(make_pair(curr->right, level+1));
            }
        }
        return nullptr;
    }
};