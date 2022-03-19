// Link: https://leetcode.com/problems/sort-list/


class Solution {
public:
    void SplitList(ListNode* head, ListNode **a, ListNode **b) {
        ListNode *fast = head;
        ListNode *slow = head;

        ListNode *tail;

        while (fast->next != NULL){
            if (fast->next->next == NULL){
                tail = slow;
                slow = slow->next;
                break;
            }
            else{
                tail = slow;
                fast = fast->next->next;
                slow = slow->next;
            }
        }
        tail->next = NULL;

        *a = head;
        *b = slow;
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
         if (l1==NULL) return l2;
         if (l2==NULL) return l1;

         if (l1->val<=l2->val){
             l1->next = mergeTwoLists(l1->next,l2);
             return l1;
         }
         else{
             l2->next = mergeTwoLists(l1,l2->next);
             return l2;
         }
    }

    ListNode* sortList(ListNode* head){
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
