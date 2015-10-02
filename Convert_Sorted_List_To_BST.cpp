/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* p = head;
        int len =0;
        while(p){
            p=p->next;
            len++;
        }
        return build(head,0,len-1);
    }
    
    TreeNode* build(ListNode*& list, int start, int end){
        if(start>end) return nullptr;
        int mid = (start+end)/2;
        TreeNode* leftChild = build(list,start,mid-1);
        TreeNode* root = new TreeNode(list->val);
        root->left = leftChild;
        list = list->next;
        root->right= build(list,mid+1,end);
        return root;
        
    }
};