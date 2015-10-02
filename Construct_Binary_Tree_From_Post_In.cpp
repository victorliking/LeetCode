/*
Given inorder and postorder traversal of a tree, construct the binary tree.
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size(),postorder,0,postorder.size());
    }
    
    TreeNode* build(vector<int>& in, int i, int ii,vector<int>& pos, int j ,int jj){
        if(i>=ii||j>=jj) return nullptr;
        TreeNode* root = new TreeNode(pos[jj-1]);
        int distance= find(in.begin()+i,in.end()+ii,pos[jj-1])-in.begin()-i;
        root->left= build(in,i,i+distance,pos,j,j+distance);
        root->right = build(in,i+distance+1,ii,pos,j+distance,jj-1);
        return root;
    }
};