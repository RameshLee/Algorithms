// Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/

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
    ListNode* mergeNodes(ListNode* head) {
        if (!head) return nullptr;

        auto sum = 0;
        while (head) {
            sum += head->val, head = head->next;  // aggregate sum, move to next node
            if (head->val == 0) break;
        }

        auto last = mergeNodes(head->next); // recursively explore & return last node
        return new ListNode(sum, last); // connect newNode & lastNode, and return the listHead.
    }
};