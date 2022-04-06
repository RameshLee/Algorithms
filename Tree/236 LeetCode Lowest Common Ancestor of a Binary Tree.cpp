// Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// 1) Recursive Approach

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

// 2) Iterative solution (record all ancestors)
/*class Solution {
public:
    vector<TreeNode*> X;
    vector<TreeNode*> Y;

    int flag;

    void findAncestors(vector<TreeNode*>& ancestors, TreeNode* root, int val){
        if (!root) return;
        if (flag) return;

        ancestors.push_back(root);

        if (val == root->val) {flag = 1;}
        findAncestors(ancestors, root->left, val);
        findAncestors(ancestors, root->right, val);

        if (!flag) ancestors.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // find all ancestors of p and q
        flag = 0; findAncestors(X, root,p->val);
        flag = 0; findAncestors(Y, root,q->val);

        // equalize the vector size
        if (X.size() > Y.size()){
            while (X.size() != Y.size())
                Y.push_back(new TreeNode(-99));
        }
        else if (X.size() < Y.size()){
            while (X.size() != Y.size())
                X.push_back(new TreeNode(-88));
        }

        //printf("X: "); for (auto& it:X) printf("%d ",it->val); cout<<endl;
        //printf("Y: "); for (auto& it:Y) printf("%d ",it->val); cout<<endl;

        // find common ancestor
        while (X.back()->val != Y.back()->val) {
            X.pop_back();Y.pop_back();
        }
        return X.back();
    }
};*/