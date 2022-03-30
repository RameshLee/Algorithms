// Link: https://leetcode.com/problems/linked-list-cycle-ii/

// 1) using two pointers approach: T=O(n), S=O(1) (Preferred)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if (!head) return head;

        ListNode* slow = head; ListNode* fast = head;
        int cycleFound = 0;

        // check for cycle
        while (fast && fast->next){
            slow = slow->next, fast = fast->next->next;
            if (slow == fast) {cycleFound = 1; break;}
        }

        // intuition: https://web.archive.org/web/20160401024212/http://learningarsenal.info:80/index.php/2015/08/24/detecting-start-of-a-loop-in-singly-linked-list/
        if (cycleFound){
            ListNode* A = head; ListNode* B = fast;

            while (1){
                if (A == B) return A;
                A = A->next;
                B = B->next;
            }
        }

        return NULL;
    }
};


// 2) using hashmap: T=O(n), S=O(n)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        unordered_map<ListNode*,int> Map;
        while (head != NULL){
            if (++Map[head] == 2) return head;
            head = head->next;
        }

        return NULL;
    }
};