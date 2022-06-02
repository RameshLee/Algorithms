// Link: https://leetcode.com/problems/add-one-row-to-tree/

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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) return new TreeNode(val, root, nullptr); // corner-case
        queue<TreeNode*> q;
        if (root) q.push(root);
        for (auto level=1; !q.empty(); level++) { // bfs/level-order-traversal
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                auto left = curr->left;
                auto right = curr->right;
                if (level+1 == depth) {
                    curr->left = new TreeNode(val, left, nullptr);
                    curr->right = new TreeNode(val, nullptr, right);
                }
                if (left)  q.push(left);
                if (right) q.push(right);
            }
            if (level+1 == depth) return root;
        }
        return nullptr;
    }
};