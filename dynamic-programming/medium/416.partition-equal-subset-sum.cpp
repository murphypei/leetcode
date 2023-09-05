/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
  bool canPartition(vector<int> &nums) {
    if (nums.size() <= 1) {
      return false;
    }
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) {
      return false;
    }
    int target = sum / 2;

    // dp[i][j] 表示 nums[0...i] 能否组成和为 j 的子集
    vector<vector<int>> dp(nums.size(), vector<int>(target + 1, 0));
    for (int i = 0; i <= target; ++i) {
      dp[0][i] = (nums[0] == i);
    }
    for (int i = 1; i < nums.size(); ++i) {
      for (int j = 0; j <= target; ++j) {
        if (j >= nums[i]) {
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i]];
        } else {
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    return dp[nums.size() - 1][target];
  }
};
// @lc code=end
