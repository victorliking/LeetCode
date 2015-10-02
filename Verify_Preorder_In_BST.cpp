/*
Given an array of numbers, verify whether it is the correct preorder traversal sequence of a binary search tree.

You may assume each number in the sequence is unique.
*/

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int mi = INT_MIN;
        stack<int> stk;
        for(auto c :preorder){
            if(c<mi) return false;
            while(!stk.empty()&&c>stk.top()){
                mi = stk.top();
                stk.pop();
            }
            stk.push(c);
        }
        return true;
        
    }
};