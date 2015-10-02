/*
Divide two integers without using multiplication, division and mod operator.

If it is overflow, return MAX_INT.
*/
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor||(dividend==INT_MIN&&divisor==-1))
            return INT_MAX;
        int sign = ((dividend<0)^(divisor<0))?-1:1;
        long long dd = labs(dividend);
        long long dr = labs(divisor);
        int res =0;
        while(dd>=dr){
            long long temp = dr, multiple=1;
            while(dd>=(temp<<1)){
                temp<<=1;
                multiple<<=1;
            }
            dd -= temp;
            res += multiple;
        }
        return sign==1?res:-res;
    }
};