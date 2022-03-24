// Link: https://leetcode.com/problems/binary-tree-level-order-traversal/

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

// 1) Recursive Solution (100% faster)
class Solution {
public:
    void helper(TreeNode* root, int level, vector<vector<int>> &output){
        if (!root) return;
        if (output.size() < level+1) output.push_back(vector<int>());

        output[level].push_back(root->val);
        helper(root->left, level+1, output);
        helper(root->right, level+1, output);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> output;
        helper(root,0,output);
        return output;
    }

};

// 2) Iterative Solution using BFS+Queue (100% faster)
class Solution {
public: vector<vector<int>> output;

    void BFS(TreeNode* root){
        TreeNode* temp;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            int size=q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                temp = q.front(); q.pop();

                level.push_back(temp->val);
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
            }
            output.push_back(level);
        }
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root!=NULL) BFS(root);
        return output;
    }
};