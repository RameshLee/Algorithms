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
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for (int i=0; i<inorder.size(); i++){
            Map[inorder[i]] = i;
        }
        return helper(0, inorder.size()-1, preorder, inorder);
    }
private:
    unordered_map<int,int> Map;
    int j = 0;

    TreeNode* helper(int start, int end, vector<int>& preorder, vector<int>& inorder) {

        if (start>end){
            j--; return nullptr;
        }

        int i = Map[preorder[j]];
        TreeNode* root = new TreeNode(inorder[i]);
        j++; root->left = helper(start, i-1, preorder, inorder);
        j++; root->right = helper(i+1, end, preorder, inorder);
        return root;
    }
};

