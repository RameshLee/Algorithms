// Link: https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
using vi = vector<int>;
using um = unordered_map<int,int>;

class Solution {
public: int j;
    TreeNode* helper(int start, int end, vi& inorder, vi& postorder, um& Map){
        if (start > end) {
            j++; return NULL;
        }

        int i = Map[postorder[j]];
        TreeNode* root = new TreeNode(inorder[i]);
        j--; root->right = helper(i+1, end, inorder, postorder, Map);
        j--; root->left = helper(start, i-1, inorder, postorder, Map);
        return root;
    }

    TreeNode* buildTree(vi& inorder, vi& postorder){
        um Map;
        for (int i=0; i<inorder.size(); i++){
            Map[inorder[i]] = i;
        }
        j = postorder.size()-1;
        return helper(0, postorder.size()-1, inorder, postorder, Map);
    }
};