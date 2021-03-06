/*
Reverse a singly linked list.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre =nullptr, *next;
        while(head){
            next = head->next;
            head->next =pre;
            pre = head;
            head =next;
        }
        return pre;
    }
};