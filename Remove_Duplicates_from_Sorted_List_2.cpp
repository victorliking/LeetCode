/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode sb(-1);
        ListNode *pre = &sb;
        pre->next= head;
        head= pre;
        ListNode*p = head;
        while(p->next){
            ListNode* p2 = p->next;
            while(p2->next&&p2->next->val==p2->val){
                p2 = p2->next;
            }
            if(p->next!=p2){
                p->next = p2->next;
            }
            else p =p->next;
        }
        return sb.next;
    }
};