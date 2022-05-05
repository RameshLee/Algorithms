// Link: https://leetcode.com/problems/binary-tree-postorder-traversal/

// 1) iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vec;
        stack<TreeNode*> Stack, rightChildStack;
        TreeNode* curr = root;
        while (!Stack.empty() || curr) {
            if (curr) {
                Stack.push(curr); // push parent
                if (curr->right) {
                    rightChildStack.push(curr->right); // push rightChild
                }
                curr = curr->left; // keep going left
            }
            else {
                curr = Stack.top();
                if (!rightChildStack.empty() && curr->right == rightChildStack.top()) {
                    rightChildStack.pop();
                    curr = curr->right;
                }
                else {
                    vec.push_back(curr->val);
                    Stack.pop();
                    curr = nullptr;
                }
            }
        }
        return vec;
    }
};

// 2) recursive
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        helper(root);
        return vec;
    }
private:
    vector<int> vec;
    void helper(TreeNode* root) {
        if (!root) return;
        helper(root->left);
        helper(root->right);
        vec.push_back(root->val);
    }
};
