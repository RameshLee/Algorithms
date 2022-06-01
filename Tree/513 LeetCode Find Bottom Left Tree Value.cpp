// Link: https://leetcode.com/problems/find-bottom-left-tree-value/

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
    int findBottomLeftValue(TreeNode* root) {
        auto STRANGE = -9999;
        int result = STRANGE;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) { // bfs/level-order-traversal
            int sz = q.size(), first = STRANGE;
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                if (first == STRANGE) first = curr->val;
                if (curr->left)  q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            result = first;
        }
        return result;
    }
};