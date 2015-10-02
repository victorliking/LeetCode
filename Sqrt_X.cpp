/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        int first = 1,last = x/2;
        int last_mid;
        while(first<=last){
            int mid = (last+first)/2;
            if(x/mid>mid){
                first = mid+1;
                last_mid =mid;
            }
            else if (x/mid<mid){
                last = mid-1;
            }
            else return mid;
        }
        return last_mid;
    }
};