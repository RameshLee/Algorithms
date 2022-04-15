// Link: https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    vector<vector<int>> verticalOrder(TreeNode* root) {

        using vi = vector<int>;
        using vvi = vector<vi>;
        using pvi = pair<int,vi>;

        // apply bfs and update vectors at index positions
        unordered_map<int,vi> Map;
        queue<pair<TreeNode*,int>> q;
        if (root) q.push(make_pair(root, 0));
        while (!q.empty()){
            TreeNode* root = q.front().first;
            int index = q.front().second; q.pop();

            Map[index].push_back(root->val);

            if (root->left) q.push(make_pair(root->left, index-1));
            if (root->right) q.push(make_pair(root->right, index+1));
        }

        // order indices from left to right
        priority_queue<pvi, vector<pvi>, greater<pvi>> pq;
        for (auto it=Map.begin(); it!=Map.end(); it++){
            pq.push(make_pair(it->first, it->second));
        }

        // extract output
        vector<vector<int>> ret;
        while (!pq.empty())
            ret.push_back(pq.top().second), pq.pop();
        return ret;
    }
};