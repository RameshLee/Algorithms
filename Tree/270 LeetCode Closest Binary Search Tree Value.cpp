// Link: https://leetcode.com/problems/closest-binary-search-tree-value/

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
    void InOrderTraversal(TreeNode *root, vector<int>& arr){
        if (!root) return;

        InOrderTraversal(root->left, arr);
        arr.push_back(root->val);
        InOrderTraversal(root->right, arr);
    }

    int closestValue(TreeNode* root, double target) {

        vector<int> arr;
        InOrderTraversal(root, arr);

        double minDiff = DBL_MAX;
        int closest = 0;
        for (auto& it:arr)
            if (abs(it-target) < minDiff)
                minDiff = abs(it-target), closest = it;

        return closest;
    }
};