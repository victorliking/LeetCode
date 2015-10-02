/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        dfs(ret,nums,0,nums.size());
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int> nums, int i ,int j){
        if(i==j-1){
            ret.push_back(nums);
            return;
        }
        for(int k  =i;k<j;k++){
            if(i!=k&&nums[i]==nums[k]) continue;
            swap(nums[i],nums[k]);
            dfs(ret,nums,i+1,j);
        }
    }
};