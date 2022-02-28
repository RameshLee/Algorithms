// Problem: https://leetcode.com/problems/merge-two-sorted-lists/
// Solution: Merge Two Sorted Linked List at O(n+m) time complexity

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
         ListNode *tail = NULL;
         ListNode *head = NULL;

         while (list2 != NULL || list1 != NULL)
         {
             if (list2 == NULL)
             {
                if (head == NULL)
                    head = list1;
                else
                    tail->next = list1;

                tail = list1;
                list1 = list1->next;
             }
             else if (list1 == NULL)
             {
                if (head == NULL)
                    head = list2;
                else
                    tail->next = list2;

                tail = list2;
                list2 = list2->next;
             }
             else if (list1->val <= list2->val)
             {
                if (head == NULL)
                    head = list1;
                else
                    tail->next = list1;

                tail = list1;
                list1 = list1->next;
             }
            else
            {
                if (head == NULL)
                    head = list2;
                else
                    tail->next = list2;

                tail = list2;
                list2 = list2->next;
            }

         }

         return head;
    }
};