/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 */

// @lc code=start
class Solution {
public:
  int numSquares(int n) {
    if (n <= 1) {
      return n;
    }

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
      dp[i] = i;
      for (int j = sqrt(i); j >= 0; --j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
        // printf("i: %d, j: %d, dp[i]: %d\n", i, j, dp[i]);
      }
    }
    return dp[n];
  }
};
// @lc code=end
