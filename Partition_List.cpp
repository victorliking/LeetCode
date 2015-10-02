/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
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
    ListNode* partition(ListNode* head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode* left = &left_dummy;
        ListNode* right = & right_dummy;
        
        for(ListNode* cur=head;cur;cur=cur->next){
            if(cur->val<x){
                left->next = cur;
                left = left->next;
            }
            else {
                right->next = cur;
                right = right->next;
            }
        }
        left->next = right_dummy.next;
        right->next = nullptr;
        return left_dummy.next;
    }
};