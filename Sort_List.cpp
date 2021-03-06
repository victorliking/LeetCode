/*
Sort a linked list in O(n log n) time using constant space complexity.
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
    ListNode* sortList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return head;
        ListNode* slow=head,*fast=head;
        while(fast->next&&fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow ;
        slow = slow->next;
        fast->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        
        ListNode*ret = merge(l1,l2);
        return ret;
    }
    
    ListNode* merge(ListNode* l1, ListNode* l2){
        ListNode dummy(-1);
        ListNode* cur = &dummy;
        for(;l1&&l2;cur=cur->next){
            if(l1->val<l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else{
                cur->next = l2;
                l2 = l2->next;
            }
        }
        
        if(!l1) cur->next = l2;
        if(!l2) cur->next = l1;
        
        return dummy.next;
    }
};