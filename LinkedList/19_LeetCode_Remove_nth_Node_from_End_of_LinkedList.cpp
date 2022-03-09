//Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/

/*
Algorithm:
1) Find the middle node using fast-slow method.
2) Compute the target element's index.
3) Traverse from either first or middle node until the delete action.
Time complexity = O(n) + O(n/2) = O(n)
Space complexity = O(1)
*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        if (head->next == NULL)
        {
            head = NULL;
            return head;
        }

        ListNode *fast;
        ListNode *slow;

        fast = head;
        slow = head;

        int i = 0;
        int j = 0;

        // find middle node, so that we can start deleting from first or middle elem to save time
        while (fast->next != NULL)
        {
            if (fast->next->next == NULL)
            {
                //slow = slow->next;
                fast = fast->next;
                j += 1;
                break;
            }
            else
            {
                fast = fast->next->next;
                slow = slow->next;
                i += 1;
                j += 2;
            }
        }


        ListNode *temp;
        int elem_index = (j+1) - n;
        if (elem_index == 0) //delete the first delement
            head = head->next;
        else if (elem_index > i) //traverse from middle to last element
        {
            temp = slow;
            int index = i;
            while (temp->next != NULL)
            {
                if ((index+1) == elem_index) //next elem needs to be deleted
                {
                    if (temp->next->next == NULL)
                        temp->next = NULL;
                    else
                        temp->next = temp->next->next;
                    break;
                }
                else
                {
                    temp = temp->next;
                    index++;
                }
            }
        }
        else //traverse from first to middle element
        {
            temp = head;
            int index = 0;
            while (temp->next != NULL)
            {
                if ((index+1) == elem_index) //next elem needs to be deleted
                {
                    temp->next = temp->next->next;
                    break;
                }
                else
                {
                    temp = temp->next;
                    index++;
                }
            }
        }

        return head;

    }
};