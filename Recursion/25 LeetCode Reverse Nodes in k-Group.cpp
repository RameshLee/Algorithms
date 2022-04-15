// Link: https://leetcode.com/problems/reverse-nodes-in-k-group/

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
public: int k;
    ListNode* helper(ListNode* start){

        // ensure there are k nodes
        ListNode* temp = start;
        for (int i=0; i<k; i++){
            if (!temp) return start;
            temp = temp->next;
        }

        // recursively goto the next part
        ListNode* last = helper(temp);

        // inverse the part of the list
        ListNode *prev = start, *curr = start->next, *nxtNode = nullptr;
        for (int i=1; i<k; i++){
            nxtNode = curr->next;
            curr->next = prev, prev = curr, curr = nxtNode;
        }

        // connect the reversed lists
        start->next = last;
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int _k) {
        k = _k;
        return helper(head);
    }
};