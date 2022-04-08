// Link: https://leetcode.com/problems/merge-k-sorted-lists/

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
    ListNode* mergeKLists(vector<ListNode*>& l) {

        using pi = pair<int,int>;
        priority_queue<pi, vector<pi>, greater<pi>> pq;

        ListNode* SentinelHead = new ListNode(-99);
        ListNode* prev = SentinelHead;

        for (int i=0; i<l.size(); i++){ // push the first three ele into the priority-Q
            if (l[i]) pq.push(make_pair(l[i]->val,i));
        }

        while (!pq.empty()){ // extract the max elements and create a new linkedList
            int val = pq.top().first;
            int i = pq.top().second;

            ListNode* temp = new ListNode(val); // form the new linked list
            prev->next = temp;
            prev = temp;

            pq.pop(); // pop off the max element

            l[i] = l[i]->next;
            if (l[i]) pq.push(make_pair(l[i]->val,i)); // push next ele from the same list

        }

        return SentinelHead->next;
    }
};