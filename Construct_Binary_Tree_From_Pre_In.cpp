/*
Given preorder and inorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
    
    TreeNode* build(vector<int>&pre, int i ,int ii, vector<int>& in, int j ,int jj){
        if(i>=ii||j>=jj) return nullptr;
        TreeNode* root = new TreeNode(pre[i]);
        int distance = find(in.begin()+j,in.end()+jj,pre[i]) - in.begin()-j;
        root->left = build(pre,i+1,i+1+distance,in,j,j+distance);
        root->right = build(pre,i+1+distance,ii,in,j+distance+1,jj);
    }
};