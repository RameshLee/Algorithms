// Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

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

// Approach: Exploit the relationship between inorder & preorder traversal vector to recursively build the BST.

using vi = vector<int>;
using um = unordered_map<int,int>;

class Solution {
public: int j = 0;
    TreeNode* helper(int start, int end, vi& preorder, vi& inorder, um& Map) {

        if (start>end){ j--; return NULL; }

        int i = Map[preorder[j]];
        TreeNode* root = new TreeNode(inorder[i]);
        j++; root->left = helper(start, i-1, preorder, inorder, Map);
        j++; root->right = helper(i+1, end, preorder, inorder, Map);
        return root;
    }

    TreeNode* buildTree(vi& preorder, vi& inorder) {
        um Map;
        for (int i=0; i<inorder.size(); i++){
            Map[inorder[i]] = i;
        }
        return helper(0, inorder.size()-1, preorder, inorder, Map);
    }
};

