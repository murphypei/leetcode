/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
  int findMaxForm(vector<string> &strs, int m, int n) {
    // 典型的背包问题，dp[i][j]表示前i个物品放入j容量中，能获得的最大价值。
    // 对于这道题，前i个物品就是字符串，j容量这里比较特殊，需要同时考虑两个约束条件。
    // 定义dp[k][i][j]表示在[0...k-1]组成的字符串中，i个0、j个1能够拼出的最大字符串个数
    vector<vector<vector<int>>> dp(
        strs.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int k = 1; k <= strs.size(); ++k) { // 对于每个字符串
      int zero = 0, one = 0;
      for (const auto &c : strs[k - 1])
        c == '0' ? ++zero : ++one;
      for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= n; ++j) {
          // 只有这个物品不超过容量，才有可能放入背包中。
          if (i - zero >= 0 && j - one >= 0)
            dp[k][i][j] = max(dp[k - 1][i - zero][j - one] + 1,
                              dp[k - 1][i][j]); // 选或不选
          else
            dp[k][i][j] = dp[k - 1][i][j]; // 继承之前的值
        }
      }
    }
    return dp[strs.size()][m][n];
  }
};
// @lc code=end
