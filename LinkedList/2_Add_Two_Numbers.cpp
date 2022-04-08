// Link: https://leetcode.com/problems/add-two-numbers/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        vector<int> vec1;
        vector<int> vec2;

        // 1) Vectorize the LinkedList
        while (l1 != NULL) vec1.push_back(l1->val), l1 = l1->next;
        while (l2 != NULL) vec2.push_back(l2->val), l2 = l2->next;

        // 2) Perform carry-forward summation of two vectors
        vector<int> sumVec;
        int i=0,j=0,A=0,B=0,sum=0,Carry=-1;
        while(i<vec1.size() || j<vec2.size()){

            A=0, B=0;

            if (i < vec1.size())    A = vec1[i], i++;
            if (j < vec2.size())    B = vec2[j], j++;

            if (Carry == -1)        sum = (A+B)%10,       Carry = (A+B)/10;
            else                    sum = (A+B+Carry)%10, Carry = (A+B+Carry)/10;

            sumVec.push_back(sum);
        }
        if (Carry>0)sumVec.push_back(Carry);

        // 3) Create a new linkedlist to store the values
        ListNode *Head = NULL;
        ListNode *Curr;
        for (auto& it:sumVec){
            if (Head == NULL){
                Head = new ListNode(it);
                Curr = Head;
            }
            else{
                Curr->next = new ListNode(it);
                Curr = Curr->next;
            }
        }
        return Head;
    }
};