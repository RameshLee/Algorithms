// Link: https://leetcode.com/problems/validate-binary-search-tree/
//In-order traversal of a BST gives a sorted array

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
    vector<int> vec;
    bool decision = true;

    void inOrderTraversal(TreeNode* root){

        if (decision==false) return; // exit-condition
        if (!root) return; // base-case

        inOrderTraversal(root->left); // recurrence
        vec.push_back(root->val);
        if (vec.size()>1 && vec[vec.size()-2] >= vec[vec.size()-1]) decision = false; // exit-condition
        inOrderTraversal(root->right); // recurrence
    }

    bool isValidBST(TreeNode* root) {

        inOrderTraversal(root);
        return decision;
    }
};