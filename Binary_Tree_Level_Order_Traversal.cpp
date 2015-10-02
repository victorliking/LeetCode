/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(root,ret,1);
        return ret;
    }
    
    void traverse(TreeNode* root, vector<vector<int>>&ret,int level){
        if(!root) return;
        if(level>ret.size()) ret.push_back(vector<int>());
        ret[level-1].push_back(root->val);
        traverse(root->left,ret,level+1);
        traverse(root->right,ret,level+1);
    }
};