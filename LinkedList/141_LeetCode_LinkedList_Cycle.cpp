// Link: https://leetcode.com/problems/linked-list-cycle/

//Algo: LinkedList consist of a cycle if slow & fast pointers meet at some point.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (head == NULL) return false;
        if (head->next == NULL) return false;
        if (head->next->next == NULL) return false;

        ListNode* fast = head;
        ListNode* slow = head;

        while (fast != NULL)
        {
            slow = slow->next;
            fast = (fast->next == NULL)?fast->next:fast->next->next;

            if (slow == fast) return true;
        }

        return false;
    }
};