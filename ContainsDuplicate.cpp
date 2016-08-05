// Given an array of integers, find if the array contains any duplicates. 
//
// Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

/**
 * 利用hash表
 */
 
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> num_map;
        num_map.clear();
        for(size_t i = 0; i < nums.size(); ++i) {
            ++num_map[nums[i]];
            if(num_map[nums[i]] > 1) {
                return true;
            }
        }
        return false;
    }
};