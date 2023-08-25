/*
 * @lc app=leetcode id=300 lang=cpp
 *
 * [300] Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int lengthOfLIS(vector<int> &nums) {
    if (nums.size() <= 1) {
      return nums.size();
    }

    vector<int> dp(nums.size(), 1);
    dp[0] = 1;
    int dp_max = dp[0];
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = i - 1; j >= 0; --j) {
        if (nums[i] > nums[j]) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      dp_max = max(dp_max, dp[i]);
    }
    return dp_max;
  }
};
// @lc code=end
