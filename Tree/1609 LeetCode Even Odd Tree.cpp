// Link: https://leetcode.com/problems/even-odd-tree/

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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        if (root) q.push(root);
        vector<int> level;
        for (auto index=0; !q.empty(); index++) { // bfs/level-order-traversal
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                level.push_back(curr->val);
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);

                // checking exit conditions
                if (index%2 == 0 && curr->val%2 == 0) return false; // even index, odd value
                if (index%2 != 0 && curr->val%2 != 0) return false; // odd index, even value
                if (level.size() >= 2) {
                    int n = level.size();
                    if (index%2==0 && level[n-1] <= level[n-2]) return false; // strictly increase
                    if (index%2!=0 && level[n-1] >= level[n-2]) return false; // strictly decrease
                }
            }
            level.clear();
        }
        return true;
    }
};