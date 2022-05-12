// Link: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left, *right;
 * };
 */
class Solution {
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> A,B,C;
        helper(root1, A); // inordertraversal of BST is a sorted array
        helper(root2, B); // inordertraversal of BST is a sorted array
        return merge(A,B,C); // merge two sorted arrays
    }
private:
    void helper(TreeNode* root, vector<int>& vec) {
        if (!root) return;

        helper(root->left, vec);
        vec.push_back(root->val);
        helper(root->right, vec);
    }

    vector<int> merge(vector<int>& A, vector<int>& B, vector<int>& C) {
        int i=0, j=0, n=A.size(), m=B.size();
        while (1) {
            if (i>=n && j>=m)       break;
            else if (i>=n)          C.push_back(B[j]), j++;
            else if (j>=m)          C.push_back(A[i]), i++;
            else if (A[i] <= B[j])  C.push_back(A[i]), i++;
            else if (A[i] > B[j])   C.push_back(B[j]), j++;
        }
        return C;
    }
};