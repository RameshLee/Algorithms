// Link: https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

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
    void flatten(TreeNode* root) {
        if (!root) return;

        // generate a copy of flatten linked list
        helper(root);

        // replace the list nodes with original nodes
        curr = SentinelHead->right;
        while (curr->right) {
            TreeNode* right = curr->right;
            TreeNode* Node = Map[curr];
            Node->left = nullptr;
            Node->right = right;
            curr = right;
        }
    }
private:
    unordered_map<TreeNode*,TreeNode*> Map;
    TreeNode *SentinelHead = new TreeNode(-99);
    TreeNode* curr = SentinelHead;

    void helper(TreeNode* root) {
        if (!root) return;

        curr->right = new TreeNode(root->val);
        curr = curr->right;
        Map[curr] = root;

        helper(root->left);
        helper(root->right);
    }
};