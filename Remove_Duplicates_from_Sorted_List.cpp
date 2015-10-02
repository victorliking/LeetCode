/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
        if(head==nullptr) return nullptr;
        for(ListNode* pre = head,*cur=pre->next;cur;cur=cur->next){
            if(pre->val==cur->val){
                pre->next = cur->next;
                delete cur;
            }
            else pre = cur;
        }
        return head;
    }
};

