// Link: https://leetcode.com/problems/cousins-in-binary-tree/

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
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*,int> P1, P2; // (parent,level)
        queue<pair<TreeNode*,TreeNode*>> q; // (curr, parent)
        if (root) q.push(make_pair(root,root));
        for (auto level=0; !q.empty(); level++) { // level-order-traversal
            auto sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front().first;
                auto parent = q.front().second; q.pop();
                if (curr->val == x) P1 = make_pair(parent, level);
                if (curr->val == y) P2 = make_pair(parent, level);
                if (curr->left) q.push(make_pair(curr->left, curr));
                if (curr->right) q.push(make_pair(curr->right, curr));
            }
        }
        return (P1.first->val == P2.first->val || P1.second != P2.second) ? false : true;
    }
};