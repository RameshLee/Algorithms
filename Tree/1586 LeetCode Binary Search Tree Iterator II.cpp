// Link: https://leetcode.com/problems/binary-search-tree-iterator-ii/

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
        // inorderTraversal: convert bst to linkedlist
        stack<TreeNode*> Stack;
        TreeNode* curr = root;
        while (!Stack.empty() || curr) {
            if (curr) {
                Stack.push(curr);
                curr = curr->left;
            }
            else {
                l.push_back(Stack.top()); // update linked list
                curr = Stack.top(); Stack.pop();
                curr = curr->right;
            }
        }
        this->n = l.size(); // list size
    }

    bool hasNext() {
        return (i+1 < n) ? true : false;
    }

    int next() {
        return l[++i]->val;
    }

    bool hasPrev() {
        return (i-1 < n && i-1 >= 0) ? true : false;
    }

    int prev() {
        return l[--i]->val;
    }
private:
    vector<TreeNode*> l; int n;
    int i = -1;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */