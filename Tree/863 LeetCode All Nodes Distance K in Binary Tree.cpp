// Link:

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        // create adjacency list
        helper(root);
        this->n = graph.size(), this->k = k;

        // apply dfs and record values at reach k
        dfs(target->val);
        return result;
    }
private:
    int n, k, depth = 0; vector<int> result;
    unordered_map<int,vector<int>> graph;
    unordered_map<int,int> visited;

    TreeNode* helper(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* left  = helper(root->left);
        TreeNode* right = helper(root->right);

        if (left) {
            graph[root->val].push_back(left->val);
            graph[left->val].push_back(root->val);
        }
        if (right) {
            graph[root->val].push_back(right->val);
            graph[right->val].push_back(root->val);
        }
        return root;
    }

    void dfs(int i) {
        if (visited.find(i) != visited.end()) return;
        if (depth == k) result.push_back(i);

        visited[i] = 1, depth++;
        for (auto j:graph[i]) {
            dfs(j);
        }
        depth--;
    }
};