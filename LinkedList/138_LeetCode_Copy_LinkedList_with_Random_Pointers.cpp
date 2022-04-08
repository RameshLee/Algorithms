//Problem: https://leetcode.com/problems/copy-list-with-random-pointer/
//Method: A simple approach to insert new nodes in between original nodes

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        Node *curr;

        // 1) insert new nodes in between original nodes
        curr = head;
        while (curr != NULL){
            Node *temp = new Node(curr->val);
            temp->next = curr->next;
            curr->next = temp;
            curr = temp->next;
        }

        // 2) copy random pointers from original to new nodes
        curr = head;
        while (curr != NULL){
            if (curr->random) curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        // 3) cut off original nodes from the list
        Node *newHead = NULL;
        Node *newCurr = NULL;
        if (head) newHead = head->next, newCurr = newHead;

        curr = head;
        while (curr){
            curr->next = curr->next->next;
            curr = curr->next;

            if (newCurr->next) newCurr->next = newCurr->next->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};