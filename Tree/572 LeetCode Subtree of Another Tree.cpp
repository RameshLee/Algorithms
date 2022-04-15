// Link: https://leetcode.com/problems/subtree-of-another-tree/

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
// 1) brute force: encode every subtree as a string, and compare two strings.

class Solution {
private: string a,b; bool decision = false;
public:
    void helper(TreeNode* root){
        if (!root) return;
        if (decision) return;

        b.clear();
        dfs(root,b);
        if (b==a) decision = true;

        helper(root->left);
        helper(root->right);
    }

    void dfs(TreeNode* root, string &s){
        if (!root) {
            s += "N ";
            return;
        }

        s += to_string(root->val);
        s += " ( ";
        s += "L", dfs(root->left,s);
        s += "R", dfs(root->right,s);
        s += ") ";
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        dfs(subRoot,a);
        printf("a=%s\n",a.c_str());
        helper(root);
        return decision;
    }
};