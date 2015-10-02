/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int>> ret;
        int target =0;
        if(num.size()<3) return ret;
        sort(num.begin(),num.end());
        auto last = num.end();
        for(auto a = num.begin();a<prev(last,2);a++){
            auto b = next(a);
            auto c = prev(last);
            while(b<c){
                if(*a+*b+*c<target) b++;
                else if (*a+*b+*c>target) c--;
                else {
                    vector<int> path(3,0);
                    path[0]=*a;
                    path[1]=*b;
                    path[2]=*c;
                    ret.push_back(path);
                    while(b<c&&*b==path[1]) b++;
                    while(b<c&&*c==path[2]) c--;
                }
            }
            while(a<prev(last)&&*a==*(a+1)) a++;
        }
        
        return ret;
    }
};