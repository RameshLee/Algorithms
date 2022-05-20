// Link: https://leetcode.com/problems/same-tree/

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

// 1) recursive approach
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;
        if (!p || !q) return false;

        return ((p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
    }
};

// 2) iterative approach
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return true;

        // bfs/level-order-traversal
        queue<TreeNode*> q1, q2;
        q1.push(p); q2.push(q);
        while (!q1.empty()) {
            auto a = q1.front(); q1.pop();
            auto b = q2.front(); q2.pop();

            if (!a && !b) continue;
            if (!a || !b) return false;
            if (a->val != b->val) return false;

            if (a) q1.push(a->left);
            if (a) q1.push(a->right);
            if (b) q2.push(b->left);
            if (b) q2.push(b->right);
        }
        return true;
    }
};