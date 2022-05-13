// Link: https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val; TreeNode *left, *right;
 * };
 */

// Approach: Construct BT from inorder and preorder traversal is EQUIVALENT to Construct BST from preorder.
// Because, inorder traversal of BST is a sorted array!

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        this->inorder  = preorder;
        sort(inorder.begin(), inorder.end()); // inorderTraversal of BST is a sorted array!
        for (int i=0; i<inorder.size(); i++) {
            Map[inorder[i]] = i; // record the positions
        }
        return helper(0,inorder.size()-1,inorder,preorder);
    }
private:
    vector<int> inorder; unordered_map<int,int> Map;
    int j = 0;

    TreeNode* helper(int start, int end, vector<int>& inorder, vector<int>& preorder) {
        if (start > end) {
            j--; return nullptr;
        }
        int index = Map[preorder[j]];
        TreeNode* root = new TreeNode(inorder[index]);
        j++; root->left  = helper(start,index-1,inorder,preorder);
        j++; root->right = helper(index+1,end,inorder,preorder);
        return root;
    }
};