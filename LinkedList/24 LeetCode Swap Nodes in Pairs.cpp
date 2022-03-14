// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Algo: 3-Pointers Iterative Approach with O(N) time complexity

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
    ListNode* swapPairs(ListNode* head){

        if (head == NULL) return head;
        if (head->next == NULL) return head;

        ListNode *SentinelHead = new ListNode(-99, head);

        ListNode* trail = SentinelHead;
        ListNode* prev = head;
        ListNode* temp = head->next;

        while (temp != NULL){

            // perform swapping
            trail->next = temp;
            prev->next = temp->next;
            temp->next = prev;

            if (prev->next == NULL) break;

            // select next nodes to swap
            trail = prev;
            prev = prev->next;
            temp = prev->next;
        }

        return SentinelHead->next;
    }
};