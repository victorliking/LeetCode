/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        ListNode dummy(-1);
        ListNode* p =&dummy;
        for(;l1!=nullptr&&l2!=nullptr;p=p->next){
            if(l1->val<l2->val){
                p->next = l1;
                l1 = l1->next;
            }
            else{
                p->next = l2;
                l2 = l2->next;
            }
        }
        
        p->next = l1==nullptr?l2:l1;
        return dummy.next;
    }
};