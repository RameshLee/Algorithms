// Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/

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
    string smallestFromLeaf(TreeNode* root) {
        helper(root);
        return Best;
    }
private:
    string s; string Best;

    void helper(TreeNode* root) {
        if (!root) return;
        // make move
        s.push_back(root->val + 'a');
        if (!root->left && !root->right) {
            string curr = s;
            std::reverse(curr.begin(), curr.end());
            if (Best.empty()) Best = curr;
            else if (curr < Best) Best = curr;
        }

        helper(root->left);
        helper(root->right);

        // undo move
        s.pop_back();
    }
};