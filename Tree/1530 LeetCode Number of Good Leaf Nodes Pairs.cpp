// Link: https://leetcode.com/problems/recover-binary-search-tree/

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

// using graph
class Solution {
public:
    int countPairs(TreeNode* root, int distance) {
        // create adjacency list
        createAdjList(root);

        // apply dfs
        for (auto i:leafNodes) {
            dfs(i,i,0,distance);
        }
        return goodPairs/2;
    }
private:
    unordered_map<TreeNode*,vector<TreeNode*>> graph;
    unordered_set<TreeNode*> leafNodes, visited;
    int goodPairs = 0;

    void createAdjList(TreeNode* root) {
        if (!root) return;

        // create adjacency list
        if (root->left) {
            graph[root].push_back(root->left);
            graph[root->left].push_back(root);
        }
        if (root->right) {
            graph[root].push_back(root->right);
            graph[root->right].push_back(root);
        }

        // append leaf nodes
        if (!root->left && !root->right) leafNodes.insert(root);

        createAdjList(root->left);
        createAdjList(root->right);
    }

    void dfs(TreeNode* start, TreeNode* i, int reach, int distance) {
        if (visited.count(i)) return;
        if (reach > distance) return;
        if (i != start && leafNodes.count(i)) goodPairs++;

        visited.insert(i);
        for (auto j:graph[i])
            dfs(start, j, reach+1, distance);
        visited.erase(i);
    }
};