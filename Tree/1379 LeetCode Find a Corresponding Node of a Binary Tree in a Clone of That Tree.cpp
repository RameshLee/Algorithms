// Link: https://leetcode.com/problems/find-a-corresponding-node-of-a-binary-tree-in-a-clone-of-that-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1) iterative
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        stack<TreeNode*> Stack;
        if (cloned) Stack.push(cloned);
        while (!Stack.empty()) { // pre-order traversal
            TreeNode* curr = Stack.top(); Stack.pop();
            if (curr->val == target->val) return curr;
            if (curr->right) Stack.push(curr->right);
            if (curr->left) Stack.push(curr->left);
        }
        return nullptr;
    }
};

// 2) recursive
class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        helper(cloned, target);
        return Node;
    }
private:
    TreeNode* Node;

    void helper(TreeNode* root, TreeNode* target) {
        if (!root) return;
        if (root->val == target->val) Node = root;
        helper(root->left, target);
        helper(root->right, target);
    }
};