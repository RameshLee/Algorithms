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
        Node *curr = head;
        Node *nextNode;

        // 1) insert new nodes in between original nodes
        while (curr != NULL)
        {
            nextNode = curr->next;
            Node *NewNode = new Node(curr->val);
            curr->next = NewNode;
            NewNode->next = nextNode;
            curr = curr->next->next;
        }

        //print utility
        curr = head;
        while (curr != NULL)
        {
            printf("%d ", curr->val);
            curr = curr->next;
        }

        // 2) copy random pointers from original to new nodes
        curr = head;
        while (curr != NULL)
        {
            nextNode = curr->next->next;
            if (curr->random != NULL)
                curr->next->random = curr->random->next;
            curr = nextNode;
        }

        // 3) cut off original nodes from the list
        Node *newHead = NULL;
        Node *newCurr = NULL;
        curr = head;

        if (head != NULL)
        {
            newHead = head->next;
            newCurr = newHead;
        }

        while (curr != NULL && newCurr != NULL)
        {
            curr->next = curr->next->next;
            curr = curr->next;

            if (newCurr->next != NULL)
                newCurr->next = newCurr->next->next;
            newCurr = newCurr->next;
        }

        return newHead;
    }
};