/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. 
If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). 
You are responsible to gather all the input requirements up front.
*/

class Solution {
public:
    int myAtoi(string str) {
        int sum=0,sign=1,i=0,n=str.size();
        
        while(str[i]==' '&&i<n) i++;
        
        if(str[i]=='+') sign=1,i++;
        else if (str[i]=='-') sign =-1,i++;
        
        for(;i<n;i++){
            if(str[i]<'0'||str[i]>'9') break;
            if(sum>INT_MAX/10||(sum==INT_MAX/10&&str[i]-'0'>INT_MAX%10)){
                return sign==1?INT_MAX:INT_MIN;
            }
            sum = sum*10+str[i]-'0';
        }
        return sum*sign;
    }
};