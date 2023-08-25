/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 */

// @lc code=start
class Solution {
public:
  int numDecodings(string s) {
    if (s.empty() || s[0] == '0') {
      return 0;
    }
    if (s.size() == 1) {
      return 1;
    }

    int n = s.size();
    // dp[i]表示前i个字符的解码方法数
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++) {
      // 因为dp[i]初始化为0，所以类似斐波那契数列，将前面两种情况都加上

      // 首先判断当前字符是否可以单独解码
      if (s[i - 1] != '0') {
        dp[i] += dp[i - 1];
      }

      // 然后判断当前字符和前一个字符是否可以一起解码
      if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6')) {
        dp[i] += dp[i - 2];
      }

      // 两种情况都不成立，则无法解码
      if (dp[i] == 0) {
        return 0;
      }
    }
    return dp[n];
  }
};
// @lc code=end
