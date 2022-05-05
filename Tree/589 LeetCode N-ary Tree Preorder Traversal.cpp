// Link: https://leetcode.com/problems/n-ary-tree-preorder-traversal/

// 1) iterative
class Solution {
public:
    vector<int> preorder(Node* root) {
        if (!root) return vector<int>();

        vector<int> vec;
        stack<Node*> Stack;
        Stack.push(root);
        while (!Stack.empty()) {
            Node* curr = Stack.top(); Stack.pop();
            vec.push_back(curr->val);

            // insert right-before-left to ensure visiting the leftChild first.
            for (int i=curr->children.size()-1; i>=0; i--) {
                Stack.push(curr->children[i]);
            }
        }
        return vec;
    }
};

// 2) recursive
class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> vec;
        helper(root, vec);
        return vec;
    }
private:
    void helper(Node* root, vector<int>& vec) {
        if (!root) return;
        vec.push_back(root->val);
        for (auto it:root->children) {
            helper(it,vec);
        }
    }
};