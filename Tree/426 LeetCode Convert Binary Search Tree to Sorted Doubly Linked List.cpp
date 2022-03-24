// Link: https://leetcode.com/problems/convert-binary-search-tree-to-sorted-doubly-linked-list/

//1) Vectorize the BST using inOrderTraversal
//2) Create a doubly linked list with the vector

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
    vector<int> vec;

    void InOrderTraversal(Node* root) {

        if (!root) return;
        InOrderTraversal(root->left);
        vec.push_back(root->val);
        InOrderTraversal(root->right);
    }

    Node* helper(Node* prev, int i){

            if (i==vec.size()) {return prev;}

            Node* temp = new Node(vec[i]);
            prev->right = temp;
            temp->left = prev;

            return helper(temp, i+1);
    }

    Node* treeToDoublyList(Node* root) {

        // corner-cases
        if (!root) return root;
        if (!root->left && !root->right) {
            root->left = root; root->right = root;
            return root;
        }

        // vectorize the array with InOrderTraversal of BST
        InOrderTraversal(root);

        // create a new doubly linked list
        Node* head = new Node(vec[0]);
        Node* tail = helper(head,1);
        head->left = tail;
        tail->right = head;

        return head;
    }
};