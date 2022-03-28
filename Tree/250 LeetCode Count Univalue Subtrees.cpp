// Link: https://leetcode.com/problems/count-univalue-subtrees/

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
    int count = 0;

    int isUniValue(TreeNode* root, int val){

        stack<TreeNode*> s;

        s.push(root);

        while (!s.empty()){

            TreeNode* Node = s.top(); s.pop();

            if (Node->val != val) return 0;

            if (Node->left) s.push(Node->left);
            if (Node->right) s.push(Node->right);
        }

        return 1;
    }

    void Traverse(TreeNode* root){
        if (!root) return;

        count += isUniValue(root, root->val);
        Traverse(root->left);
        Traverse(root->right);
    }

    int countUnivalSubtrees(TreeNode* root){
        Traverse(root);

        return count;
    }
};