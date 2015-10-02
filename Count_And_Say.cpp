/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string countAndSay(int n) {
        string ret = "1";
        for(int i =1;i<n;i++){
            ret = say(ret);
        }
        return ret;
    }
    
    string say(string& ret){
        string s;
        for(int i =0,j,k;i<ret.size();i=j,k=0){
            k=1,j=i+1;
            while(j<ret.size()&&ret[i]==ret[j]) j++,k++;
            s += char(k+'0');
            s += ret[i];
        }
        return s;
    }
};