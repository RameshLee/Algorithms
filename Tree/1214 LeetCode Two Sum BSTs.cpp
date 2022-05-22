// Link: https://leetcode.com/problems/two-sum-bsts/

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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {

        unordered_set<int> Set1, Set2;
        helper(root1, Set1);
        helper(root2, Set2);

        for (auto c:Set1) {
            if (Set2.count(target-c))
                return true;
        }
        return false;
    }
private:
    void helper(TreeNode* root, unordered_set<int>& Set) {
        if (!root) return;
        Set.insert(root->val);
        helper(root->left, Set);
        helper(root->right, Set);
    }
};