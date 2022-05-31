// Link: https://leetcode.com/problems/check-if-a-string-is-a-valid-sequence-from-root-to-leaves-path-in-a-binary-tree/

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
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        this->arr = arr;
        helper(root, 0);
        return result;
    }
private:
    vector<int> arr;
    bool result = false;

    void helper(TreeNode* root, int i) {
        if (!root || i >= arr.size() || arr[i] != root->val) return;
        if (i==arr.size()-1 && arr[i] == root->val && !root->left && !root->right) result = true;
        helper(root->left, i+1);
        helper(root->right, i+1);
    }
};