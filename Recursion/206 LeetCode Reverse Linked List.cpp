// Link: https://leetcode.com/problems/reverse-linked-list/

class Solution {
public:
    ListNode* tail;
    int count = 0;
    void helper(ListNode* temp, ListNode* prev){
        if (temp){
            helper(temp->next, prev->next);
            if (prev->val != -999) temp->next = prev; // cut off the sentinel head
            if (count == 0) { tail = temp; count++;} // record the tail
            prev->next = NULL;
        }
    }

    ListNode* reverseList(ListNode* head) {

        ListNode *SentinelHead = new ListNode(-999,head);
        ListNode* temp = head;
        ListNode* prev = SentinelHead;

        helper(temp, prev);

        return tail;
    }
};
