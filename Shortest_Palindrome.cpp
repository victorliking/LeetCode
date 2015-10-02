/*
Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.

For example:

Given "aacecaaa", return "aaacecaaa".

Given "abcd", return "dcbabcd".
*/

class Solution {
public:
    string shortestPalindrome(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        int n = s.size(),l;
        for(l=n;l>=0;l--){
            if(s.substr(0,l)==s2.substr(n-l))
                break;
        }
        
        return s2.substr(0,n-l)+s;
    }
};