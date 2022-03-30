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

// 1) Recursive approach: T=O(n), S=O(1)

class Solution {
public:
   // ListNode* tail;
    void helper(ListNode* curr, ListNode* prev, ListNode** tail, ListNode* SentinelHead){

        if (!curr) { *tail = prev; return; } // base-case: record the tail

        helper(curr->next, prev->next, tail, SentinelHead); // recursion
        if (prev != SentinelHead) curr->next = prev; // cut off the sentinel head
        prev->next = NULL;

    }

    ListNode* reverseList(ListNode* head) {

        if (!head) return head;

        ListNode *SentinelHead = new ListNode(-99,head);
        ListNode* prev = SentinelHead;
        ListNode* curr = head;
        ListNode* tail;

        helper(curr, prev, &tail, SentinelHead);

        return tail;
    }
};

/*
// 2) Iterative approach: T=O(n), S=O(1)

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
};*/