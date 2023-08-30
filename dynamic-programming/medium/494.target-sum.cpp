/*
 * @lc app=leetcode id=494 lang=cpp
 *
 * [494] Target Sum
 */

// @lc code=start
class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int target) {
    return dfs(nums, nums.size() - 1, target);
  }

  int dfs(vector<int> &nums, int end, int target) {
    if (end == 0) {
      return int(nums[0] == target) + int(nums[0] == -target);
    }
    return dfs(nums, end - 1, target + nums[end]) +
           dfs(nums, end - 1, target - nums[end]);
  }
};
// @lc code=end
