// Link: https://leetcode.com/problems/correct-a-binary-tree/

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

// bfs: level order traversal from right to left, and check whether curr->right is previously visited.
class Solution {
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<TreeNode*> levelSet;
        queue<TreeNode*> q;
        if (root) q.push(root);
        while (!q.empty()) { // bfs/level-order-traversal
            levelSet.clear();
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                if (curr->right) {
                    q.push(curr->right), levelSet.insert(curr->right);
                    if (levelSet.count(curr->right->right)) { // check the violation
                        curr->right = nullptr;
                        return root;
                    }
                }
                if (curr->left) {
                    q.push(curr->left), levelSet.insert(curr->left);
                    if (levelSet.count(curr->left->right)) { // check the violation
                        curr->left = nullptr;
                        return root;
                    }
                }
            }
        }
        return root;
    }
};