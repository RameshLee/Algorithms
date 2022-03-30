// Link: https://leetcode.com/problems/remove-linked-list-elements/

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

// 1) SentinelHead approach: T=O(n), S=O(1)

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        ListNode* SentinelHead = new ListNode(-99,head);
        ListNode* temp = head;
        ListNode* prev = SentinelHead;

        while(temp!= NULL){
            if (temp->val == val) {
                prev->next = temp->next, temp = temp->next;
            }
            else{
                 prev = prev->next, temp = temp->next;
            }
        }

        return SentinelHead->next;

    }
};