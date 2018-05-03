// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for(i = 0; i < nums.size() - 1; i++) {
            for(j = nums.size() - 1; j > i; j--) {
                if(nums[i] + nums[j] == target) {
                    return vector<int>{i,j};
                }
            }
        }
        
    }
};