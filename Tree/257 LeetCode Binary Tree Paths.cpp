// Link: https://leetcode.com/problems/binary-tree-paths/

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
    vector<string> binaryTreePaths(TreeNode* root) {
        helper(root);
        return result;
    }
private:
    vector<string> result; string path;

    void helper(TreeNode* root) {
        if (!root) return;

        path += to_string(root->val); // add number
        path += "->"; // add arrow

        if (!root->left && !root->right) { // extract output
            result.push_back(path.substr(0,path.size()-2));
        }

        helper(root->left); // recursively explore
        helper(root->right);

        path.pop_back(), path.pop_back(); // remove arrow
        while (!path.empty() && std::isdigit(path[path.size()-1])) path.pop_back(); // remove num
        if (!path.empty() && path[path.size()-1] == '-') path.pop_back(); // remove -ve sign
    }
};