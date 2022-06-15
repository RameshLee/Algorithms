// Link: https://leetcode.com/problems/binary-search-tree-iterator/

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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        this->root = root;
        this->curr = root;
    }

    int next() {
        while (!Stack.empty() || curr) {
            if (curr) {
                Stack.push(curr);
                curr = curr->left;
            }
            else {
                int result = Stack.top()->val;
                curr = Stack.top(); Stack.pop();
                curr = curr->right;
                return result;
            }
        }
        return -1;
    }

    bool hasNext() {
        return (!Stack.empty() || curr) ? true : false;
    }
private:
    stack<TreeNode*> Stack;
    TreeNode *curr, *root;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */