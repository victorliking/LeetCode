/*
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int m = haystack.size(),n=needle.size();
        if(n==0) return 0;
        for(int i =0;i<m-n+1;i++){
            int j =0;
            for(;j<n;j++){
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j==n) return i;
        }
        return -1;
    }
};