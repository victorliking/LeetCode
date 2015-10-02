/*
Given a binary tree, count the number of uni-value subtrees.

A Uni-value subtree means all nodes of the subtree have the same value.

For example:
Given binary tree,
              5
             / \
            1   5
           / \   \
          5   5   5
return 4.
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
    int count =0;
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return false;
        helper(root);
        return count;
    }
    
    bool helper(TreeNode* root){
        if(!root) return true;
        bool lc=true,rc = true;
        if(root->left) lc = helper(root->left)&&(root->left->val==root->val);
        if(root->right) rc = helper(root->right)&&(root->right->val==root->val);
        if(rc&&lc){
            count++;return true;
        }
        return false;
    }
};