//Problem: https://leetcode.com/problems/middle-of-the-linked-list/
//Method: fast-slow algorithm to find middle of the linked list at O(n) complexity

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
    ListNode* middleNode(ListNode* head)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        while (fast->next != NULL)
        {
            if (fast->next->next == NULL)
            {
                slow = slow->next;
                break;
            }
            else
            {
                fast = fast->next->next;
                slow = slow->next;
            }
        }

        return slow;

    }
};