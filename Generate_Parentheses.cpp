/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        helper(ret,"",n,0);
        return ret;
    }
    
    void helper(vector<string>& ret, string s, int n , int m){
        if(m==0&&n==0){
            ret.push_back(s);
            return;
        }
        if(m>0) helper(ret,s+")",n,m-1);
        if(n>0) helper(ret,s+"(",n-1,m+1);
    }
};