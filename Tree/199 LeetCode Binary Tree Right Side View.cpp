// Link: https://leetcode.com/problems/binary-tree-right-side-view/

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
    vector<int> rightSideView(TreeNode* root) {

        vector<int> vec;
        queue<TreeNode*> q;
        if (root) q.push(root);

        while (!q.empty()){
            int sz = q.size(), firstVal = INT_MAX;
            for (int i=0; i<sz; i++){
                TreeNode* node = q.front(); q.pop();
                firstVal = (firstVal==INT_MAX) ? node->val : firstVal;
                if (node->right) q.push(node->right);
                if (node->left) q.push(node->left);
            }
            vec.push_back(firstVal);
        }
        return vec;
    }
};