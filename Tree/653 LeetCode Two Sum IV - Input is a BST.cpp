// Link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/

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
    unordered_map<int,int> Map;
    bool output = false;

    void DFS(TreeNode* root, int k){

        if (root == NULL) return;

        int first = root->val;
        int second = k-root->val;

        Map[first]++;
        if (second != first)
            if (Map[second] > 0)
                output = true;

        if (output) return;

        DFS(root->left, k);
        DFS(root->right, k);
    }

    bool findTarget(TreeNode* root, int k) {

        DFS(root, k);
        return output;
    }
};