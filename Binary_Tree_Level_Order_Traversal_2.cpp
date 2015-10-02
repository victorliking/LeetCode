/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        traverse(ret,root,1);
        reverse(ret.begin(),ret.end());
        return ret;
    }
    
    void traverse(vector<vector<int>>& ret, TreeNode* root,int level){
        if(!root) return;
        if(level>ret.size()) ret.push_back(vector<int>());
        ret[level-1].push_back(root->val);
        traverse(ret,root->left,level+1);
        traverse(ret,root->right,level+1);
    }
};