/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?*/

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        Inorder(ret,root);
        return ret;
    }
    
    void Inorder(vector<int>&ret,TreeNode* root){
        if(root==nullptr) return;
        Inorder(ret,root->left);
        ret.push_back(root->val);
        Inorder(ret,root->right);
    }
};