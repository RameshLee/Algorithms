// Link: https://leetcode.com/problems/clone-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        return helper(root);
    }
private:
    Node* helper(Node* root) {
        if (!root) return nullptr;

        Node* clone = new Node(root->val);
        for (auto j:root->children) {
            clone->children.push_back(helper(j));
        }
        return clone;
    }
};