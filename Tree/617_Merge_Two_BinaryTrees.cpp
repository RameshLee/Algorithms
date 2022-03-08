// Link: https://leetcode.com/problems/merge-two-binary-trees/

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
class Solution
{
public:

    TreeNode* DFS(TreeNode* root1, TreeNode* root2)
    {
        TreeNode* newRoot;

        //merge nodes
        if (root1 == NULL && root2 == NULL)
            return NULL;
        else if (root1 != NULL && root2 != NULL)
            newRoot = new TreeNode(root1->val + root2->val);
        else if (root1 != NULL)
            newRoot = new TreeNode(root1->val);
        else if (root2 != NULL)
            newRoot = new TreeNode(root2->val);

        //next points
        newRoot->left = DFS(root1?root1->left:NULL, root2?root2->left:NULL);
        newRoot->right = DFS(root1?root1->right:NULL, root2?root2->right:NULL);

        return newRoot;
    }

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2)
    {
        //special case
        if (root1 == NULL && root2 == NULL)
            return NULL;

        return DFS(root1,root2);
    }
};

