// Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/

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
    int pairSum(ListNode* head) {
        helper(&head, head);
        return result;
    }
private:
    int result = INT_MIN;

    void helper(ListNode** start, ListNode* end) {
        if (!end) return;

        helper(start, end->next);
        result = max(result, (*start)->val + end->val);
        (*start) = (*start)->next;
    }
};