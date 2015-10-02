/*
Implement a basic calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.

You may assume that the given expression is always valid.

Some examples:
"3+2*2" = 7
" 3/2 " = 1
" 3+5 / 2 " = 5
*/

class Solution {
public:
    int calculate(string s) {
        int len;
        len = s.size();
        if(s.size()==0) return 0;
        stack<int> stk;
        int num = 0;
        char sign = '+';
        for(int i =0;i<len;i++){
            if(isdigit(s[i])){
                num = num*10+s[i]-'0';
            }
            if((!isdigit(s[i])&&s[i]!=' ')||i==len-1){
                if(sign=='-')
                    stk.push(-num);
                if(sign=='+')
                    stk.push(num);
                if(sign=='*'){
                    int temp =stk.top();
                    stk.pop();
                    stk.push(temp*num);
                }
                if(sign=='/'){
                    int temp =stk.top();
                    stk.pop();
                    stk.push(temp/num);
                }
                sign = s[i];
                num = 0;
            }
        }
        
        int ret =0;
        while(!stk.empty()){
            ret+=stk.top();
            stk.pop();
        }
        return ret;
    }
};