// Problem: https://leetcode.com/problems/merge-two-sorted-lists/
// Solution: Merge Two Sorted Linked List at O(n+m) time complexity

// 1) Recursive Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        if (l1==NULL) return l2;
        if (l2==NULL) return l1;

        if (l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


// 2) Iterative Approach

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
    {
         ListNode *Curr = NULL;
         ListNode *head = NULL;

         while (list2 != NULL || list1 != NULL)
         {
             if (list2 == NULL)
             {
                 if (head == NULL) {Curr = new ListNode(list1->val); head = Curr;}
                 else {Curr->next = new ListNode(list1->val); Curr = Curr->next;}

                 list1 = list1->next;
             }
             else if (list1 == NULL)
             {
                 if (head == NULL) {Curr = new ListNode(list2->val); head = Curr;}
                 else {Curr->next = new ListNode(list2->val); Curr = Curr->next;}
                 list2 = list2->next;
             }
             else if (list1->val <= list2->val)
             {
                 if (head == NULL) {Curr = new ListNode(list1->val); head = Curr;}
                 else {Curr->next = new ListNode(list1->val); Curr = Curr->next;}
                 list1 = list1->next;
             }
             else
             {
                 if (head == NULL) {Curr = new ListNode(list2->val); head = Curr;}
                 else {Curr->next = new ListNode(list2->val); Curr = Curr->next;}
                 list2 = list2->next;
             }
         }

         return head;
    }
};