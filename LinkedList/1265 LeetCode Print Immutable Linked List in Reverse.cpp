// Link: https://leetcode.com/problems/print-immutable-linked-list-in-reverse/

/**
 * // This is the ImmutableListNode's API interface.
 * // You should not implement it, or speculate about its implementation.
 * class ImmutableListNode {
 * public:
 *    void printValue(); // print the value of the node.
 *    ImmutableListNode* getNext(); // return the next node.
 * };
 */

class Solution {
public:
    void printLinkedListInReverse(ImmutableListNode* head) {
        helper(head);
    }
private:
    void helper(ImmutableListNode* temp) {
        if (!temp) return;

        helper(temp->getNext());
        temp->printValue();
    }
};