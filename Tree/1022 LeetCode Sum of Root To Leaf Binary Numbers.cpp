// Link: https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/

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
    int sumRootToLeaf(TreeNode* root) {
        helper(root);
        int sum = 0;
        for (auto path:allPaths) sum += stoi(path,0,2);
        return sum;
    }
private:
    vector<string> allPaths; string path;

    void helper(TreeNode* root) {
        if (!root) return; // base-case

        path.push_back(root->val + '0'); // make move
        helper(root->left); // recursion
        helper(root->right); // recursion
        if (!root->left && !root->right) allPaths.push_back(path); // add path into allPaths
        path.pop_back(); // undo move
    }
};