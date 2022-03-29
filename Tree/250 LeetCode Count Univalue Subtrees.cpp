// Link: https://leetcode.com/problems/count-univalue-subtrees/

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


// 1) Optimized solution: bottom-up approach (Preferred: 92% Faster)

class Solution {
public:
    bool isUniValue(TreeNode* root, int &count){

        if (!root) return true;

        bool left = isUniValue(root->left, count);
        bool right = isUniValue(root->right, count);

        if (!left || !right) return false;
        if (root->left && root->val != root->left->val) return false;
        if (root->right && root->val != root->right->val) return false;

        count++;
        return true;
    }

    int countUnivalSubtrees(TreeNode* root){
        int count = 0;
        isUniValue(root, count);
        return count;
    }
};

// 2) Simple solution: apply DFS from every node

class Solution {
public:
    int count = 0;
    int DFS(TreeNode* root, int val){

        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()){
            TreeNode* Node = s.top(); s.pop();
            if (Node->val != val) return 0;
            if (Node->left) s.push(Node->left);
            if (Node->right) s.push(Node->right);
        }
        return 1;
    }

    void Traverse(TreeNode* root){
        if (!root) return;
        count += DFS(root, root->val);
        Traverse(root->left);
        Traverse(root->right);
    }

    int countUnivalSubtrees(TreeNode* root){
        Traverse(root);
        return count;
    }
};