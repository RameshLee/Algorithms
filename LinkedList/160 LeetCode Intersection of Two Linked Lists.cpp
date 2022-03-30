// Link: https://leetcode.com/problems/intersection-of-two-linked-lists/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 1) Two-pointers approach; T=O(m+n), S=O(1) (Preferred: 90% Faster, 99% memory efficient)

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* curr; int n=0, m=0, startA = 0, startB = 0;

        // count lengths of two lists
        curr = headA; while (curr != NULL){ n++; curr = curr->next; }
        curr = headB; while (curr != NULL){ m++; curr = curr->next; }

        // set starting point for for the longer list
        if (n>m) {
            startA = n-m;
            int val = 0; while (val++ < startA){ headA = headA->next; }
        }
        else {
            startB = m-n;
            int val = 0; while (val++ < startB){ headB = headB->next; }
        }

        // traverse simultaneously
        while (headA != NULL && headB != NULL){
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }

        return NULL;
    }
};


// 2) Using Hashmap: T=O(m+n), S=O(m+n)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        unordered_map<ListNode*, int> Map;
        ListNode* curr;

        curr = headA;
        while (curr != NULL){
            Map[curr]++;
            curr = curr->next;
        }

        curr = headB;
        while (curr != NULL){
            if (++Map[curr] == 2) return curr;
            curr = curr->next;
        }

        return NULL;
    }
};
