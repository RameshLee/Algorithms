// Link: https://leetcode.com/problems/find-root-of-n-ary-tree/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* findRoot(vector<Node*> tree) {
        // explore tree from each node
        for (auto node:tree) {
            helper(node);
        }
        // the node that is not in childSet is the rootNode
        for (auto node:tree) {
            if (!childSet.count(node))
                return node;
        }
        return nullptr;
    }
private:
    unordered_set<Node*> childSet, visitedSet;

    void helper(Node* root) {
        if (!root || visitedSet.count(root)) return;

        visitedSet.insert(root);
        for (auto child : root->children) {
            helper(child), childSet.insert(child);
        }
    }
};