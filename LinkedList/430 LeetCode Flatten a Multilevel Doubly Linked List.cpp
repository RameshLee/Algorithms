// Link: https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/

/*
// Definition for a Node.
class Node { public: int val; Node *prev, *next, *child; };
*/

class Solution {
public:
    Node* helper(Node* temp){

        while (temp){ // traverse along the list to find active child pointers

            if (temp->child) {
                Node* last = helper(temp->child); // fetch the last node of second-level list
                last->next = temp->next;     if (temp->next) temp->next->prev = last;   // correct the back-end pointers
                temp->next = temp->child;      temp->child->prev = temp;  // correct the front-end pointers
                temp->child = NULL; // nullify the child pointer
            }

            if (!temp->next) break;
            temp = temp->next;
        }
        return temp; // return the last node
    }

    Node* flatten(Node* head) {
        if (!head) return head;
        Node* last = helper(head);
        return head;
    }
};