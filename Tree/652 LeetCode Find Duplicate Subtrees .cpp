// Link: https://leetcode.com/problems/find-duplicate-subtrees/
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
public:
    unordered_map<string, int> Map;
    vector<TreeNode*> vec;

    string helper(TreeNode* root){

        if (!root) return "";

        string l = helper(root->left);
        string r = helper(root->right);

        string temp = to_string(root->val) + "L" + l + "R" + r;
        Map[temp]++;
        if (Map[temp] == 2){
            vec.push_back(root);
        }
        return temp;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        helper(root);

        // print root nodes of repeating subtrees
        /*for (auto it=vec.begin(); it!=vec.end(); it++) {
            printf("%d ", (*it)->val);
        }*/

        return vec;
    }
};