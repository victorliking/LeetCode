/*
Given an array of integers, find out whether there are two distinct indices i and j in the array such that 
the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<int> cache;
        for(int i =0;i<nums.size();i++){
            if(i>k) cache.erase(nums[i-k-1]);
            auto pos = cache.lower_bound(nums[i]-t);
            if(pos!=cache.end()&&*pos-nums[i]<=t)
                return true;
            cache.insert(nums[i]);
        }
        return false;
    }
};