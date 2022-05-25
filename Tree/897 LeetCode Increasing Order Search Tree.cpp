// Link: https://leetcode.com/problems/increasing-order-search-tree/

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
    TreeNode* increasingBST(TreeNode* root) {
        // retreive order of each node
        helper(root);

        // create root node
        TreeNode* head = pq.top().second; pq.pop();
        head->left = nullptr;

        // tailor the tree
        TreeNode* prev = head;
        while (!pq.empty()) {
            TreeNode* curr = pq.top().second; pq.pop();
            curr->left = nullptr;
            prev->right = curr;
            prev = curr;
        }
        return head;
    }
private:
    using pi = pair<int,TreeNode*>;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    int i=0;

    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->left);
        pq.push(make_pair(++i,root));
        helper(root->right);
    }
};