/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

   1
 /   \
2     3
 \
  5
All root-to-leaf paths are:

["1->2->5", "1->3"]
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ret;
        if(root!=nullptr) helper(root,"",ret);
        return ret;
    }
    
    void helper(TreeNode* root, string path, vector<string>& ret){
        if(root->left==nullptr&&root->right==nullptr)  ret.push_back(path+to_string(root->val));
        if(root->left!=nullptr) helper(root->left,path+to_string(root->val)+"->",ret);
        if(root->right!=nullptr) helper(root->right,path+to_string(root->val)+"->",ret);
        
    }
};