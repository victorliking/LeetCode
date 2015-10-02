/*
Given a collection of integers that might contain duplicates, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If nums = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
*/

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> result;
        vector<int> path;
        helper(nums,0,path,result);
        return result;
    }
    
    void helper(vector<int>& nums, int start, vector<int>& path, vector<vector<int>>& result){
        result.push_back(path);
        for(int i = start;i!=nums.size();++i){
            if(i ==start || nums[i]!=nums[i-1]){
                path.push_back(nums[i]);
                helper(nums,start+1,path,result);
                path.pop_back();
            }
        }
    }
};

