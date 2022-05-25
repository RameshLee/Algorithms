// Link: https://leetcode.com/problems/add-two-numbers-ii/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temp; auto n1=0, n2=0;

        // compute the size of two linkedlists
        temp = l1; while (temp) temp = temp->next, n1++;
        temp = l2; while (temp) temp = temp->next, n2++;

        // equalize the size of two linkedlists
        while (n1 < n2) l1 = new ListNode(0, l1), n1++;
        while (n1 > n2) l2 = new ListNode(0, l2), n2++;

        // reverse both the linkedlists
        l1 = reverseLinkedList(l1);
        l2 = reverseLinkedList(l2);

        // perform carry-forward summation
        auto carry = 0;
        auto l3 = new ListNode(-99);
        auto curr = l3;
        while (l1 && l2) {
            auto A = l1->val, B = l2->val;
            auto sum = (A+B+carry) % 10;
            carry = (A+B+carry) / 10;

            curr->next = new ListNode(sum);
            curr = curr->next;

            l1 = l1->next, l2 = l2->next;
        }
        if (carry) curr->next = new ListNode(carry);
        return reverseLinkedList(l3->next);
    }
private:
    ListNode* reverseLinkedList(ListNode* curr) {
        ListNode* prev = nullptr;
        while (curr) {
            auto nxtPtr = curr->next;
            curr->next = prev ? prev : nullptr;
            prev = curr;
            if (!nxtPtr) return curr;
            curr = nxtPtr;
        }
        return nullptr;
    }
};