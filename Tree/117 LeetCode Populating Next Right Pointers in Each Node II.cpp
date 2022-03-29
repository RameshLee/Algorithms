// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node-ii/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void BFS(Node* root){
        queue<Node*> q;
        q.push(root);
        Node* prev;
        while (!q.empty()){

            int sz = q.size();
            for (int i=0; i<sz; i++){
                Node* curr = q.front(); q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
                if (i>0) prev->next = curr;
                prev = curr;
            }
        }
    }

    Node* connect(Node* root){
        if (!root) return root;
        BFS(root);
        return root;
    }
};