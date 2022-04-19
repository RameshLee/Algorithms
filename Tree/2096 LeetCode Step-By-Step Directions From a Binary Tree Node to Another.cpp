// Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/submissions/

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
private:
    TreeNode* LCA; int source, destination; string path, lockedPath;
    enum Directions{LEFT='L', RIGHT='R', UP='U', DOWN='D'};
public:
    int lowestCommonAncestor(TreeNode* root){
        if (!root) return 0;

        int l = lowestCommonAncestor(root->left);
        int r = lowestCommonAncestor(root->right);
        int curr = (root->val == source || root->val == destination) ? 1 : 0;

        if (curr + l + r >= 2) LCA = root;
        return (curr || l || r) ? 1 : 0;
    }

    void traverse(TreeNode* root, int val, char dir){
        if (!root) return;

        path.push_back(dir);
        if (root->val == val) lockedPath = path;

        traverse(root->left, val, LEFT);
        traverse(root->right, val, RIGHT);

        path.pop_back();
    }

    string getDirections(TreeNode* root, int _source, int _destination) {
        source = _source, destination = _destination;
        lowestCommonAncestor(root); // find LCA for source and destination

        traverse(LCA, source, DOWN); // path from source to LCA
        string A(lockedPath.substr(1).size(), UP);

        traverse(LCA, destination, DOWN); // path from LCA to destination
        string B = lockedPath.substr(1);

        return A+B;
    }
};