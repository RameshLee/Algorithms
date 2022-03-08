// Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

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

class Solution
{
public:
    Node* connect(Node* root)
    {
        if (root == NULL) return root;

        queue<Node*> q;
        q.push(root);

        Node *prev = NULL;
        while (!q.empty())
        {
            int size = q.size();
            for (int i=0; i<size; i++) //level-order traversal
            {
                Node* temp = q.front();
                q.pop();

                if (temp->left != NULL) //It's a PBT! Hence, enough to check if one child is NULL.
                {
                    q.push(temp->left);
                    q.push(temp->right);
                }

                if (i>0) prev->next = temp;
                prev = temp;
            }
        }

        return root;
    }
};