/*
Given an array of integers and an integer k, find out
 whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
*/
 class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        for(int i =0;i<nums.size();i++){
            if(map.find(nums[i])!=map.end()&&i-map[nums[i]]<=k)
            return true;
            map[nums[i]] = i;
        }
        return false;
    }
};