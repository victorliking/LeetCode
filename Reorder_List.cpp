/*
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if(head==nullptr||head->next==nullptr) return;
        ListNode*fast= head,*slow =head,*prev;
        while(fast!=nullptr&&fast->next!=nullptr){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = nullptr;
        slow = reverse(slow);
        ListNode* cur =head;
        while(cur->next){
            ListNode* temp = cur->next;
            cur->next = slow;
            slow = slow->next;
            cur->next->next =temp;
            cur = temp;
        }
        cur->next = slow;
    }
    
    
    ListNode* reverse(ListNode* head){
        ListNode* prev =nullptr,*next;
        while(head){
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
};