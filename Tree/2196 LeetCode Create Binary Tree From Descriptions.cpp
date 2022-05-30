// Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/

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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> NodeMap;
        unordered_set<int> childSet;

        // build the tree
        for (auto e:descriptions) {
            if (!NodeMap.count(e[0])) NodeMap[e[0]] = new TreeNode(e[0]); // parent
            if (!NodeMap.count(e[1])) NodeMap[e[1]] = new TreeNode(e[1]); // child
            if (e[2])  NodeMap[e[0]]->left = NodeMap[e[1]]; // leftChild
            else       NodeMap[e[0]]->right = NodeMap[e[1]]; // rightChild
            childSet.insert(e[1]); // store all children in a set
        }

        // find the root
        for (auto e:descriptions) {
            if (!childSet.count(e[0]))
                return NodeMap[e[0]]; // retrieveRoot
        }
        return nullptr;
    }
};