// Link: https://leetcode.com/problems/validate-binary-search-tree/

// 1) full recursive approach

class Solution {
public:
    bool isValidBST(TreeNode* root, TreeNode *min=NULL, TreeNode* max=NULL) {

        if (!root) return true;

        if (min && root->val <= min->val) return false;
        if (max && root->val >= max->val) return false;

        return ( isValidBST(root->left, min, root) && isValidBST(root->right, root, max) );
    }
};


// 2) exploiting property: In-order traversal of a BST gives a sorted array

class Solution {
public:
    vector<int> vec;
    bool output = true;

    void inOrderTraversal(TreeNode* root){
        if (root == NULL) return;

        inOrderTraversal(root->left);
        vec.push_back(root->val);

        if (vec.size() > 1) {
            if (vec[vec.size()-2] >=vec[vec.size()-1])
                output = false;
        }

        inOrderTraversal(root->right);
    }

    bool isValidBST(TreeNode* root) {

        inOrderTraversal(root);
        return output;

    }
};