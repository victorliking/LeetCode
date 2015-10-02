/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        helper(ret,0,nums);
        return ret;
    }
    
    void helper(vector<vector<int>>&ret, int start, vector<int>nums){
        if(start==nums.size()){
            ret.push_back(nums);
            return;
        }
        
        for(int i = start;i<nums.size();i++){
            swap(nums[start],nums[i]);
            helper(ret,start+1,nums);
            swap(nums[start],nums[i]);
        }
    }
};