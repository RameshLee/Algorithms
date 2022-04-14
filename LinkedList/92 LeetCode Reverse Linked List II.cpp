// Link: https://leetcode.com/problems/reverse-linked-list-ii/

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
class Solution {
public:
    void reverse(ListNode* prev, ListNode* curr){
        if (!curr) return;

        reverse(prev->next, curr->next);
        curr->next = prev;
        prev->next = nullptr;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {

        if (left == right) return head;

        // create SentinelHead and SentinelTail
        ListNode* SentinelHead = new ListNode(INT_MAX,head);
        ListNode* SentinelTail = new ListNode(INT_MIN);
        ListNode* curr = head;
        while (curr->next) curr = curr->next;
        curr->next = SentinelTail;

        // locate 4 nodes: start, end, beforeStart, afterEnd
        ListNode *start = SentinelHead, *end = SentinelHead, *BEFORE, *AFTER;
        for (int i=0; i<left; i++) BEFORE = start, start = start->next;
        for (int i=0; i<right; i++) end = end->next; AFTER = end->next;
        end->next = nullptr;

        // reverse the required part of the list
        reverse(start,start->next);

        // combine the reverse list with before & after nodes
        BEFORE->next = end;
        start->next = AFTER;

        // cut off the sentineltail
        curr = head;
        while (curr && curr->next){
            if (curr->next->val == SentinelTail->val)
                curr->next = nullptr;
            curr = curr->next;
        }

        return SentinelHead->next;
    }
};