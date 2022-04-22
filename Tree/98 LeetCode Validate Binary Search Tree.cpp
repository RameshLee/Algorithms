// Link: https://leetcode.com/problems/validate-binary-search-tree/

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

// Approach 1: fully recursive: T=O(N), S=O(1)

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode* Min=nullptr, TreeNode* Max=nullptr) {
        if (!root) return true;

        if (Min && root->val <= Min->val) return false;
        if (Max && root->val >= Max->val) return false;

        return ( isValidBST(root->left,Min,root) && isValidBST(root->right,root,Max) );
    }
};


// Approach 2: Exploiting property: In-order traversal of a BST gives a sorted array: T=O(N), S=O(N)

/*
class Solution {
public:
    vector<int> vec;
    bool decision = true;

    void inOrderTraversal(TreeNode* root){

        if (decision==false) return;
        if (!root) return;

        inOrderTraversal(root->left);
        vec.push_back(root->val);

        if (vec.size()>1 && vec[vec.size()-2] >= vec[vec.size()-1])
            decision = false;

        inOrderTraversal(root->right);
    }

    bool isValidBST(TreeNode* root) {

        inOrderTraversal(root);
        return decision;
    }
};
*/