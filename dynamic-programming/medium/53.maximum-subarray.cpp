/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start
class Solution {
public:
  int maxSubArray(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int res = dp[0];
    for (int i = 1; i < nums.size(); i++) {
      dp[i] = max(nums[i], dp[i - 1] + nums[i]);
      res = max(res, dp[i]);
    }
    return res;
  }
};
// @lc code=end
