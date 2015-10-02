/*
A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

Find all strobogrammatic numbers that are of length = n.

For example,
Given n = 2, return ["11","69","88","96"].
*/

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        vector<string> ret;
        if(n&1) ret= {"0","1","8"};
        else ret = {""};
        vector<string> bases = {"00", "11", "69", "88", "96"};
        int m = bases.size();
        while(n>1){
            n = n-2;
            vector<string> temp;
            for(string s: ret){
                for(int i=n<2?1:0;i<m;i++){
                    temp.push_back(bases[i][0]+s+bases[i][1]);
                }
            }
            ret = move(temp);
        }
        return ret;
    }
};