// Link: https://leetcode.com/problems/binary-tree-preorder-traversal/

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

// 1) iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {

        // corner-case
        if (!root) return vector<int>();

        vector<int> vec;
        stack<TreeNode*> Stack; Stack.push(root);
        while (!Stack.empty()) {
            TreeNode* curr = Stack.top(); Stack.pop();
            vec.push_back(curr->val);

            // push right-before-left to ensure that left is processed first
            if (curr->right) Stack.push(curr->right);
            if (curr->left)  Stack.push(curr->left);
        }
        return vec;
    }
};

// 2) recursive
/*
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        helper(root);
        return vec;
    }
private:
    vector<int> vec;
    void helper(TreeNode* root) {
        if (!root) return;
        vec.push_back(root->val);
        helper(root->left);
        helper(root->right);
    }
};
*/