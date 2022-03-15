// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

//Algo: BFS approach == Level Order Traversal

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
    vector<vector<int>> output;

    void BFS(TreeNode* root)
    {
        TreeNode* temp;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++)
            {
                temp = q.front();
                q.pop();

                level.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            output.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root)
    {
        if(root!=NULL) BFS(root);
        return output;
    }

};