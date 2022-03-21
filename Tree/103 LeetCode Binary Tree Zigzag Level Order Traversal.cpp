// Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    using vvi = vector<vector<int>>;
    using vi = vector<int>;
    using qi = queue<TreeNode*>;
	vvi output; qi q; int Reverse=0;

    vvi zigzagLevelOrder(TreeNode* root) {

        if (root==NULL) return output;

        q.push(root);
        output.push_back(vector<int>({root->val}));

        while (!q.empty()){

            vi level;
            int sz = q.size();
            for (int i=0; i<sz; i++){
                TreeNode* Node = q.front(); q.pop();
                if (Node->left) q.push(Node->left),level.push_back(Node->left->val);
                if (Node->right) q.push(Node->right),level.push_back(Node->right->val);
            }

            if (!level.empty()) {
                Reverse = (Reverse==1)?0:1;
                if (Reverse) reverse(level.begin(),level.end());
                output.push_back(level);
            }
        }
        return output;
    }
};