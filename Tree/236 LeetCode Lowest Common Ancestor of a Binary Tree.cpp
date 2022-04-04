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
    TreeNode* LCA; int flag = 0;

    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q){

        if (!root) return false;

        bool Left = dfs(root->left, p,q);
        bool Right = dfs(root->right, p,q);

        if (flag == 0){
            if (Left && Right) {
                flag = 1; LCA = root;
            }
            else if ((Left || Right) && (root->val == p->val || root->val == q->val)) {
                flag = 1; LCA = root;
            }
        }

        if (root->val == p->val || root->val == q->val) return true;
        else if (Left || Right) return true;
        else return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){

        bool Bool = dfs(root,p,q);
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