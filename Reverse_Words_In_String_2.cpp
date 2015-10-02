/*
Given an input string, reverse the string word by word. A word is defined as a sequence of non-space characters.

The input string does not contain leading or trailing spaces and the words are always separated by a single space.

For example,
Given s = "the sky is blue",
return "blue is sky the".

Could you do it in-place without allocating extra space?s
*/
class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        for(int i =0,j=0;i<s.size();i=j+1){
            for(j=i;j<s.size()&&!isblank(s[j]);j++){}
            reverse(s.begin()+i,s.begin()+j);
        }
    }
};