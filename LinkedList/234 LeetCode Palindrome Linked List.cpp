// Link: https://leetcode.com/problems/palindrome-linked-list/

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

// 1) Recursive approach: T=O(n), S=O(n) (due to recursion stack)

class Solution {
public:
    ListNode* start;

    void helper(ListNode* end, bool &Decision){

        if (!end) return; // found tail

        helper(end->next, Decision);
        if (start->val != end->val) Decision = false;
        start = start->next;
    }

    bool isPalindrome(ListNode* head) {

        bool Decision = true;
        ListNode* end = head; start = head;
        helper(end, Decision);
        return Decision;
    }
};

// 2) To achieve O(1) space: i) find middle of the list using fast-slow pointer approach,
// ii) reverse the second half, iii) compare the results, iv) restore the list.