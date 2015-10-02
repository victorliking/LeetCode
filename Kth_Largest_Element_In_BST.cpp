/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
    int kthSmallest(TreeNode* root, int k) {
        return find(root,k);
    }
    
    int find(TreeNode* root, int&k){
        if(!root) return 0;
        int res = find(root->left,k);
        if(k==0) return ret;
        if(--k==0) return root->val;
        return find(root->right,k);
    }
};