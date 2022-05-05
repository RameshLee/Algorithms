// Link: https://leetcode.com/problems/binary-tree-inorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */

// 1) iterative

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> Stack;
        TreeNode* curr = root;
        while (!Stack.empty() || curr) {
            if (curr) {
                Stack.push(curr); // add parents to the stack
                curr = curr->left; // keep going left
            }
            else {
                curr = Stack.top(); Stack.pop();
                vec.push_back(curr->val);
                curr = curr->right; // continue traversal from the right-child
            }
        }
        return vec;
    }
};

// 2) recursive

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root){
        helper(root);
        return vec;
    }
private:
    vector<int> vec;

    void helper(TreeNode* root){
        if (!root) return;
        helper(root->left);
        vec.push_back(root->val);
        helper(root->right);
    }
};