// Link: https://leetcode.com/problems/most-frequent-subtree-sum/

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
private: int maxCount = 0; unordered_map<int,int> Map;
public:
    int helper(TreeNode* root) {
        if (!root) return 0;

        int l = helper(root->left);
        int r = helper(root->right);
        int sum = root->val + l + r;

        Map[sum]++;
        maxCount = max(maxCount, Map[sum]);
        return sum;
    }

    vector<int> findFrequentTreeSum(TreeNode* root) {
        // record subtree sums and repetitions
        helper(root);

        // extract the most frequent sums
        vector<int> ret;
        for (auto it=Map.begin(); it!=Map.end(); it++)
            if (it->second == maxCount)
                ret.push_back(it->first);
        return ret;
    }
};