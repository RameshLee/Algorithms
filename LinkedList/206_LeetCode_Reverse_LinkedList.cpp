// Link: https://leetcode.com/problems/reverse-linked-list/

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
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL) return head;
        ListNode* prev = new ListNode(head->val);
        while (head->next != NULL)
        {
            head = head->next;
            ListNode* curr = new ListNode(head->val);
            curr->next = prev;
            prev = curr;
        }
        return prev;
    }
};