// Link: https://leetcode.com/problems/plus-one-linked-list/

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
    ListNode* plusOne(ListNode* head) {
        Sentinel = new ListNode(0, head);
        helper(Sentinel, head);
        return (Sentinel->val == 0) ? Sentinel->next : Sentinel;
    }
private:
    ListNode* Sentinel; int carry = 1;

    void helper(ListNode* prev, ListNode* temp) {
        if (!temp) return;

        helper(prev->next, temp->next);
        auto sum = (temp->val + carry) % 10;
        carry = (temp->val + carry) / 10;
        temp->val = sum;
        if (prev == Sentinel) Sentinel->val = carry;
    }
};