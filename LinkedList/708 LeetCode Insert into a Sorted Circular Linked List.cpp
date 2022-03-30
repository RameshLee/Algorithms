// Link: https://leetcode.com/problems/insert-into-a-sorted-circular-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     Node *next;
 *     Node() : val(0), next(nullptr) {}
 *     Node(int x) : val(x), next(nullptr) {}
 *     Node(int x, ListNode *next) : val(x), next(next) {}
 * };
 */


class Solution {
public:
    Node* firstCycle(Node* prev, Node* temp, Node* head, int val){
        Node* slow = head;
        Node* fast = head;
        while (1){

            if (prev->val <= val && val <= temp->val){ // first-cycle: search for in-between index
                prev->next = new Node(val,temp);
                return head;
            }

            prev = prev->next;
            temp = temp->next;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){ // cannot find an in-between index
                return secondCycle(prev, temp, head, val);
            }
        }
        return head;
    }

    Node* secondCycle(Node* prev, Node* temp, Node* head, int val){

        Node* slow = head;
        Node* fast = head;
        while (1){

             if (temp->val < prev->val){ // second-cycle: search for the first/last index
                 prev->next = new Node(val,temp);
                 return head;
             }

            prev = prev->next;
            temp = temp->next;
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast){ // found the first/last index
                prev->next = new Node(val,temp);
                break;
            }
        }
        return head;
    }

    Node* insert(Node* head, int val) {

        // corner-case-1: if list is empty
        if (!head){
            Node* curr = new Node(val);
            curr->next = curr;
            return curr;
        }

        // corner-case-2: if list has same values everywhere
        if (head->next == head){
            Node* curr = new Node(val,head);
            head->next = curr;
            return head;
        }

        Node* SentinelHead = new Node(-99,head);
        Node* prev = SentinelHead;
        Node* temp = head;

        // enter the list to update the prev and temp nodes
        int count = 0;
        while (++count <= 2){
            prev = prev->next;
            temp = temp->next;
        }

        return firstCycle(prev, temp, head, val);
    }
};