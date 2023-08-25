/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 */

// @lc code=start
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    // dp[i][j] 表示 s1[0..i-1] 和 s2[0..j-1] 能否交错组成 s3[0..i+j-1]
    vector<vector<bool>> dp(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    for (int i = 0; i <= s1.size(); ++i) {
      for (int j = 0; j <= s2.size(); ++j) {
        if (i == 0 && j == 0) {
          dp[i][j] = true;
        } else if (i == 0) {
          dp[i][j] = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1];
        } else if (j == 0) {
          dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
        } else {
          dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                     (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
        }
      }
    }
    return dp[s1.size()][s2.size()];
  }
};
// @lc code=end
