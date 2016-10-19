// Given an array of integers, every element appears twice except for one. Find that single one.

// Note:
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?


// 常规实现，hashmap
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(size_t i = 0; i < nums.size(); ++i){
            mp[nums[i]]++;
        }
        typedef unordered_map<int, int>::const_iterator iter;
        for(iter it = mp.begin(); it != mp.end(); ++it) {
            if(it->second < 2)
                return it->first;
        }
        return nums[0];
    }
};


// trick实现，不开辟新内存
// 原理：连个数字相同则按位异或结果为0，而0与一个数字按位异或结果为其自身
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        for(size_t i = 1; i < nums.size(); ++i){
            nums[0] = nums[0] ^ nums[i];
        }
        return nums[0];
    }
};