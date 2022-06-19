// Link: https://leetcode.com/problems/closest-leaf-in-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */
class Solution {
public:
    int findClosestLeaf(TreeNode* root, int k) {
        // create adj list
        convertTreeToGraph(root);

        // apply bfs from k
        queue<int> q; q.push(k), visited.insert(k);
        while (!q.empty()) { // bfs/level-order-traversal
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front(); q.pop();
                if (!nodeMap[curr]->left && !nodeMap[curr]->right) return curr;

                for (auto j : graph[curr]) // explore candidates
                    if (!visited.count(j))
                        q.push(j), visited.insert(j);
            }
        }
        return -1;
    }
private:
    unordered_map<int, vector<int>> graph;
    unordered_map<int, TreeNode*> nodeMap;
    unordered_set<int> visited;

    void convertTreeToGraph(TreeNode* root) {
        if (!root) return;

        convertTreeToGraph(root->left);
        convertTreeToGraph(root->right);

        nodeMap[root->val] = root;
        if (root->left)  {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }
        if (root->right) {
             graph[root->val].push_back(root->right->val);
             graph[root->right->val].push_back(root->val);
        }
    }
};