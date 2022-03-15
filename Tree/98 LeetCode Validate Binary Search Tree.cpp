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
    bool output = true;

    void inOrderTraversal(TreeNode* root){
        if (root == NULL) return;

        inOrderTraversal(root->left);
        vec.push_back(root->val);

        if (vec.size() > 1) {
            if (vec[vec.size()-2] >=vec[vec.size()-1])
                output = false;
        }

        inOrderTraversal(root->right);
    }

    bool isValidBST(TreeNode* root) {

        inOrderTraversal(root);
        return output;

    }
};