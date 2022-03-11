// Link: https://leetcode.com/problems/rotate-list/

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
class Solution
{
public:
    ListNode* rotateRight(ListNode* head, int k)
    {
        // corner-case
        if (head == NULL) return head;
        if (head->next == NULL) return head;

        // 1) find the middle/last of the linkedList using fast-slow pointer method
        ListNode* fast = head;
        int fastIndex=0;
        while (fast->next != NULL)
        {
            fastIndex=(fast->next->next!=NULL)?(fastIndex+2):(fastIndex+1);
            fast = (fast->next->next!=NULL)?fast->next->next:fast->next;
        }

        // 2) make the linkedList as a circular one
        fast->next = head;

        // 3) cut off the linkedList at the desired point
        k = k%(fastIndex+1);
        ListNode* temp = head;
        int Index=0;
        while(1)
        {
            if (Index == fastIndex-k)
            {
                head = temp->next;
                temp->next = NULL;
                break;
            }
            Index++; temp=temp->next;
        }


        return head;
    }
};