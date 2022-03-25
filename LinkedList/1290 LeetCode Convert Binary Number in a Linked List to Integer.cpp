// Link: https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/

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
    int getDecimalValue(ListNode* head) {

        // fast-slow pointer approach to find total elements
        ListNode* temp = head; int count = 1;
        while (temp->next != NULL){

            count = (temp->next->next) ? count+2 : count+1;
            temp = (temp->next->next) ? temp->next->next : temp->next;
        }

        // convert binary to integer
        int val = 0;
        while (count-- >=0 && head){
            val += (head->val) * (int)pow(2,count);
            head = head->next;
        }

        return val;
    }
};