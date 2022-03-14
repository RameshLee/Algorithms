// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/

// Method: Create a dummy head to avoid corner cases in which head nodes might need to be removed!

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
    ListNode* deleteDuplicates(ListNode* head){

        ListNode *SentinelHead = new ListNode(-99, head);
        ListNode* temp = SentinelHead;
        ListNode* prev = SentinelHead;

        while (temp!= NULL){

            ListNode* curr = temp;

            int count = -1;
            while (temp != NULL && temp->val == curr->val){
                temp = temp->next;
                count++;
            }

            if (count > 0) prev->next = temp;
            else prev = curr;
        }

        return SentinelHead->next;
    }
};