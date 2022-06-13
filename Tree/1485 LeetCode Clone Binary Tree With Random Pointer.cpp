// Link: https://leetcode.com/problems/clone-binary-tree-with-random-pointer/

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    NodeCopy* copyRandomBinaryTree(Node* root) {
        auto head = copyNodes(root);
        copyRandomNodes(root);
        return head;
    }
private:
    unordered_map<Node*,NodeCopy*> Map;

    NodeCopy* copyNodes(Node* root) {
        if (!root) return nullptr;
        Map[root] = new NodeCopy(root->val);
        Map[root]->left = copyNodes(root->left);
        Map[root]->right = copyNodes(root->right);
        return Map[root];
    }

     void copyRandomNodes(Node* root) {
        if (!root) return;
        if (root->random) Map[root]->random = Map[root->random];
        copyRandomNodes(root->left);
        copyRandomNodes(root->right);
    }
};