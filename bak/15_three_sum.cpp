// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:

// The solution set must not contain duplicate triplets.

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size() < 3) {
            return result;
        }

        std::sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            int left = i + 1, right = nums.size() - 1;
            
            while(left < right) {
                if(nums[left] + nums[right] == -nums[i]) {        
                    result.push_back({nums[i], nums[left], nums[right]});
                    while(++left < right && nums[left] == nums[left-1])
                        continue;
                    while(left < --right && nums[right] == nums[right+1])
                        continue;
                } 
                else if(nums[left] + nums[right] < -nums[i]) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }
        return result;
    }
};