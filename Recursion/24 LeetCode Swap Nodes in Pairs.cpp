// Link: https://leetcode.com/problems/swap-nodes-in-pairs/

class Solution {
public:
    void swap(ListNode* first, ListNode* second){
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;

        if (second->next && second->next->next)
            swap(second->next, second->next->next);
    }

    ListNode* swapPairs(ListNode* head){

        if (head!=NULL && head->next!=NULL)
            swap(head, head->next);

        return head;
    }
};