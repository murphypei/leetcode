/*
 * @lc app=leetcode id=213 lang=cpp
 *
 * [213] House Robber II
 */

// @lc code=start
class Solution {
public:
  int rob(vector<int> &nums) {
    vector<int> dp(nums.size(), 0);
    if (dp.size() == 1)
      return nums[0];

    // 假设第一间房参与被偷，则最后一间房一定不能被偷
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    int best1 = max(dp[0], dp[1]);
    for (int i = 2; i < nums.size() - 1; ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      best1 = max(best1, dp[i]);
    }
    // printf("best1: %d\n", best1);

    // 假设第一间房不被偷，则最后一间房可以被偷
    dp[0] = 0;
    dp[1] = nums[1];
    int best2 = max(dp[0], dp[1]);
    for (int i = 2; i < nums.size(); ++i) {
      dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
      best2 = max(best2, dp[i]);
    }
    // printf("best2: %d\n", best2);

    return max(best1, best2);
  }
};
// @lc code=end
