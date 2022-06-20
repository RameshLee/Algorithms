// Link: https://leetcode.com/problems/delete-nodes-and-return-forest/

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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        targetSet.insert(to_delete.begin(), to_delete.end());
        helper(root, root);

        for (auto e:rootSet) {
            if (e && !targetSet.count(e->val))
                result.push_back(e);
        }
        return result;
    }
private:
    unordered_set<int> targetSet;
    unordered_set<TreeNode*> rootSet;
    vector<TreeNode*> result;

    TreeNode* helper(TreeNode* root, TreeNode* parent) {
        if (!root) return nullptr;

        if (targetSet.count(root->val)) { // scrap this node
            rootSet.insert(parent);
            rootSet.insert(root->left);
            rootSet.insert(root->right);

            root->left = helper(root->left, root->left);
            root->right = helper(root->right, root->right);
            return nullptr;
        }

        root->left = helper(root->left, parent);
        root->right = helper(root->right, parent);
        return root;
    }
};