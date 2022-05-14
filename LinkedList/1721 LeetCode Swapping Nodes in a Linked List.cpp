// Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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

// 1) one-pass approach
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        helper(head, k);
        int val = A->val;
        A->val = B->val;
        B->val = val;
        return head;
    }
private:
    ListNode *A, *B; int i=0, j=0, size=0;

    void helper(ListNode *temp, int k) {
        if (!temp) {
            size = i, j = size;
            return;
        }

        if (++i == k) A = temp;
        helper(temp->next, k);
        if (--j == size-k) B = temp;
    }
};

// 2) three-pass approach
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* A, *B; int size = 0;

        // find the list size
        ListNode* temp = head;
        while (temp) temp = temp->next, size += 1;

        // find the two nodes
        temp = head; for (int i=0; i<k-1; i++) temp = temp->next; A = temp;
        temp = head; for (int i=0; i<size-k; i++) temp = temp->next; B = temp;

        // swap the values
        int val = A->val;
        A->val = B->val;
        B->val = val;
        return head;
    }
};