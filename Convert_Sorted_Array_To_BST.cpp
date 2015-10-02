/*Given an array where elements are sorted in ascending order, convert it to a height balanced BST.*/

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums.begin(),nums.end());
    }
    
    TreeNode* build(vector<int>::iterator begin, vector<int>::iterator end){
        auto len = distance(begin,end);
        if(len<=0) return nullptr;
        auto mid = begin + len/2;
        TreeNode* root = new TreeNode(*mid);
        root->left = build(begin,mid);
        root->right = build(mid+1,end);
        return root;
    } 
}