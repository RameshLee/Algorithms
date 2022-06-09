// Link: https://leetcode.com/problems/find-elements-in-a-contaminated-binary-tree/

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
class FindElements {
public:
    FindElements(TreeNode* root) {
        queue<pair<TreeNode*,int>> q;
        if (root) q.push(make_pair(root,0));
        while (!q.empty()) { // bfs/level-order-traversal
            int sz = q.size();
            for (auto loop=0; loop<sz; loop++) {
                auto curr = q.front().first;
                auto x = q.front().second; q.pop();
                Set.insert(x);
                if (curr->left) q.push(make_pair(curr->left, 2*x+1));
                if (curr->right) q.push(make_pair(curr->right, 2*x+2));
            }
        }
    }

    bool find(int target) {
        return Set.count(target);
    }
private:
    unordered_set<int> Set;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */