/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
  int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
      return 1;
    }
    // 需要分为第一个数为0和第一个数不为0两种可能。
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 10;

    for (int i = 2; i <= n; i++) {
      // 第一个数不为0
      int count = 9;
      for (int j = i; j > 1; j--) {
        count *= (11 - j);
      }
      // 加上第一个数为0的可能性dp[i-1]
      dp[i] = dp[i - 1] + count;
    }
    return dp[n];
  }
};
// @lc code=end
