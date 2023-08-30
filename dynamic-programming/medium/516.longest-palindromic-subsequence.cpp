/*
 * @lc app=leetcode id=516 lang=cpp
 *
 * [516] Longest Palindromic Subsequence
 */

// @lc code=start
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    if (s.empty())
      return 0;
    vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
    // dp[i][j] 表示 s[i...j]的最长回文子序列的长度
    for (int i = s.size() - 1; i >= 0; i--) {
      dp[i][i] = 1;
      for (int j = i + 1; j < s.size(); j++) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
        // printf("%d %d %d\n", i, j, dp[i][j]);
      }
    }
    return dp[0][s.size() - 1];
  }
};
// @lc code=end
