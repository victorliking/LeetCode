/*
Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
*/

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        int n = nums.size();
        if(n==0) return ret;
        for(int i =0;i<n;){
            int start = i,end =i;
            while(end+1<n&&nums[end+1]==nums[end]+1) end++;
            if(end>start){
                ret.push_back(to_string(nums[start])+"->"+to_string(nums[end]));
            }
            else 
                ret.push_back(to_string(nums[start]));
            i = end +1;
        }
        return ret;
    }
};