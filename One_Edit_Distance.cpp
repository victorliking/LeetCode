/*
Given two strings S and T, determine if they are both one edit distance apart.
*/

class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int m = s.size(),n = t.size();
        bool check = true;
        if(m>n) return isOneEditDistance(t,s);
        if(n-m>1) return false;
        for(int i =0;i<m;i++){
            if(s[i]!=t[i]){
                if(m==n) s[i]=t[i];
                else s.insert(i,1,t[i]);
                check = false;
                break;
            }
        }
        return (check&&n-m==1)||(!check&&s==t);
    }
};