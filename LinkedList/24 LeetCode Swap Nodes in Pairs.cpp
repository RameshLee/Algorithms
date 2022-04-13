// Link: https://leetcode.com/problems/swap-nodes-in-pairs/
// Algo: 3-Pointers Iterative Approach with O(N) time complexity

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

// 1) swap using pointer

class Solution {
public:
    ListNode* helper(ListNode* prev, ListNode* curr){

        if (!curr) return prev;
        if (!prev) return nullptr;

        printf("prev: %d, curr: %d\n", prev->val, curr->val);

        ListNode* last;
        if (prev->next->next) last = helper(prev->next->next, curr->next->next);
        else last = nullptr;

        curr->next = prev;
        prev->next = last;

        return curr;
    }

    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        return helper(head, head->next);
    }
};

// 2) swap using value

/*class Solution {
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
};*/