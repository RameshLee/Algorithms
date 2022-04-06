// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1) Solution I (shortcut/efficient): but, works only for BST

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if ((root -> val > p -> val) && (root -> val > q -> val)) {
            return lowestCommonAncestor(root -> left, p, q);
        }
        if ((root -> val < p -> val) && (root -> val < q -> val)) {
            return lowestCommonAncestor(root -> right, p, q);
        }
        return root;
    }
};

// 2) Solution II: recursive approach: works for any binary tree (need not to be BST)

class Solution {
public:
    TreeNode* LCA; bool flag = false;

    int helper(TreeNode* root, TreeNode* p, TreeNode* q){

        if (!root) return 0;

        int Left = helper(root->left, p,q); // left subtree consists of p or q
        int Right = helper(root->right, p,q); // right subtree consists of p or q
        int Curr = (root->val == p->val || root->val == q->val); // curr node is p or q

        if (Left + Right + Curr >= 2) LCA = root; // record LCA

        if (Left || Right || Curr) return 1;
        return 0;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        helper(root,p,q);
        return LCA;
    }
};

// 3) Solution III: Iterative

class Solution {
public:
    vector<TreeNode*> X;
    vector<TreeNode*> Y;

    void findAncestors(vector<TreeNode*>& ancestors, TreeNode* root, int val){
        if (!root) return;
        ancestors.push_back(root);

        if (val == root->val) return;
        if (val < root->val)  findAncestors(ancestors, root->left, val);
        else                  findAncestors(ancestors, root->right, val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // find all ancestors of p and q
        findAncestors(X, root,p->val);
        findAncestors(Y, root,q->val);

        // equalize the vector size
        if (X.size() > Y.size()){
            while (X.size() != Y.size())
                Y.push_back(new TreeNode(-99));
        }
        else if (X.size() < Y.size()){
            while (X.size() != Y.size())
                X.push_back(new TreeNode(-88));
        }

        // find common ancestor
        while (X.back()->val != Y.back()->val) {
            X.pop_back();Y.pop_back();
        }
        return X.back();
    }
};