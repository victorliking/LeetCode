/*
Reverse digits of an integer.
Example1: x = 123, return 321
Example2: x = -123, return -321
*/


class Solution {
public:
    int reverse(int x) {
        long sum  =0;
        for(;x;x/=10){
            sum = sum*10 +x%10;
        }
        if(sum>INT_MAX||sum<INT_MIN){
            return 0;
        }
        return sum;
    }
};