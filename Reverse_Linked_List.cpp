/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        n = n-m;
        ListNode dummy(-1);
        ListNode* pre = &dummy;
        pre->next = head;
        while(--m) pre = pre->next;
        ListNode* start = pre->next;
        while(n--){
            ListNode* p = start->next;
            start->next = p->next;
            p->next =pre->next;
            pre->next = p;
        }
        return dummy.next;
    }
};