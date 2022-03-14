// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list/

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
    ListNode* deleteDuplicates(ListNode* head) {

        unordered_map<int,int> Map;

        ListNode* temp = head;
        ListNode* prev = head;

        while (temp!= NULL){
            Map[temp->val]++;

            if (Map[temp->val] > 1){
                prev->next = (temp->next==NULL)?NULL:temp->next;
                temp = temp->next;
            }
            else{
                prev = temp;
                temp = temp->next;
            }
        }

        return head;
    }
};