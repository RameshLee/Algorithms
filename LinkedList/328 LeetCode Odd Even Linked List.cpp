// Link: https://leetcode.com/problems/odd-even-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

 // Approach: form connections of two linked lists and merge them: T=O(n), S=O(1).

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {

        // corner-cases
        if (!head) return head;
        if (!head->next) return head;

        ListNode* curr = head; ListNode* second = head->next;
        ListNode* temp; ListNode* tail; ListNode* prev_to_tail;

        // keep connecting the curr->next to curr->next->next
        int count = 1;
        while (curr->next){

            temp = curr->next;
            curr->next = curr->next->next;

            if (!curr->next) prev_to_tail = curr;
            tail = temp;
            curr = temp;

            count++;
        }

        // connect the last node of 1st list to the first node of 2nd list.
        if (count%2 == 0) prev_to_tail->next = second;
        else tail->next = second;

        return head;
    }
};