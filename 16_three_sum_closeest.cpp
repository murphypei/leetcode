// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. 
// Return the sum of the three integers. You may assume that each input would have exactly one solution.


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if(nums.size() < 3) {
            std::cerr << "nums size must >= 2" << std::endl;
            return -1;
        }
        else if (nums.size() == 3) {
            return nums[0] + nums[1] + nums[2];
        }

        std::sort(nums.begin(), nums.end());

        int left, right, result;
        int diff = INT_MAX;
        int sum = 0;
        for(int i = 0; i < nums.size() - 2; ++i) {
            left = i + 1;
            right = nums.size() - 1;
            while(left < right) {
                sum = nums[i] + nums[left] + nums[right];
                if(sum == target) {
                    return target;
                }
                else if (sum > target) {
                    right--;
                }
                else {
                    left++;
                }
                if(diff > abs(sum - target)) {
                    diff = abs(sum - target);
                    result = sum;
                }              
            }
        }
        return result;
    }
};