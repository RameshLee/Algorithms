// Link:

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

// 1) Approach: return vector at each node that consists of all subTree node values

class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        helper(root);
        return count;
    }
private:
    int count = 0;

    vector<int> helper(TreeNode* root) {
        if (!root) return vector<int>();

        vector<int> l = helper(root->left);
        vector<int> r = helper(root->right);

        vector<int> vec = {root->val};
        vec.insert(vec.end(), l.begin(), l.end());
        vec.insert(vec.end(), r.begin(), r.end());

        if (average(vec) == root->val) count++;
        return vec;
    }

    int average(vector<int>& vec){
        int sum = 0; for (auto i:vec) sum += i;
        return (sum/vec.size());
    }
};