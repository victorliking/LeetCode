/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, max_len = 1,n = s.size();
        bool check[1000][1000] ={false};
        for(int i=n-1;i>=0;i--){
            for(int j=i;j<n;j++){
                if(s[i]==s[j]&&(j-i<2||check[i+1][j-1])){
                    check[i][j]  = true;
                    if(j-i+1>max_len){
                        max_len = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,max_len);
    }
};