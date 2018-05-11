// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> tmp(nums.begin(), nums.end());
        std::sort(tmp.begin(), tmp.end());
        int i = 0;
        int j = tmp.size() - 1;
        while(i < j) {
            if(tmp[i] + tmp[j] == target) {
                i = std::find(nums.begin(), nums.end(), tmp[i]) - nums.begin();
                j = nums.rend() - std::find(nums.rbegin(), nums.rend(), tmp[j]) - 1;
                return vector<int>{i,j};
            }
            else if(tmp[i] + tmp[j] > target) {
                j--;
            }
            else {
                i++;
            }
        }
    }
};