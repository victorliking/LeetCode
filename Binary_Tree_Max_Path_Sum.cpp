/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.
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
    int sum;
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        pathSum(root);
        return sum;
    }
    
    int pathSum(TreeNode* root){
        if(!root) return 0;
        int left = max(0,pathSum(root->left));
        int right = max(0,pathSum(root->right));
        sum = max(sum,left+right+root->val);
        return max(left,right)+root->val;
    }
};