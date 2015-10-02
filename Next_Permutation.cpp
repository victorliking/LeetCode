/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.empty()) return;
        int i ;
        for(i = nums.size()-2;i>=0;i--){
            if(nums[i]<nums[i+1]) break;
        }
        
        reverse(begin(nums)+i+1,end(nums));
        
        if(i==-1) return;
        auto iter = upper_bound(begin(nums)+i+1,end(nums),nums[i]);
        swap(nums[i],*iter);
    }
};