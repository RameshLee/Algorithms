// Problem: https://leetcode.com/problems/sort-list/
// Method: MergeSort a LinkedList at O(n*log(n)) time complexity


#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    void SplitList(ListNode* head, ListNode **a, ListNode **b)
    {
        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *tail;

        while (fast->next != NULL)
        {
            if (fast->next->next == NULL)
            {
                tail = slow;
                slow = slow->next;
                break;
            }
            else
            {
                tail = slow;
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        tail->next = NULL;

        *a = head;
        *b = slow;
    }

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

    ListNode* sortList(ListNode* head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        ListNode *a; ListNode *b;

        SplitList(head,&a,&b); //head of second list

        a = sortList(a);
        b = sortList(b);

        head = mergeTwoLists(a,b);

        return head;

    }
};

int main()
{
    ListNode *head = NULL;
    ListNode *temp = NULL;

    ListNode *NewNode = new ListNode(4);
    head = NewNode;
    temp = head;

    NewNode = new ListNode(2);
    temp->next = NewNode;
    temp = temp->next;

    NewNode = new ListNode(1);
    temp->next = NewNode;
    temp = temp->next;

    NewNode = new ListNode(5);
    temp->next = NewNode;
    temp = temp->next;

    NewNode = new ListNode(3);
    temp->next = NewNode;
    temp = temp->next;

        NewNode = new ListNode(8);
    temp->next = NewNode;
    temp = temp->next;

        NewNode = new ListNode(7);
    temp->next = NewNode;
    temp = temp->next;

    ListNode *tail = head;
    while (tail != NULL)
    {
        printf("%d ", tail->val);
        tail = tail->next;
    }printf("\n");

    Solution S;
    S.sortList(head);


}