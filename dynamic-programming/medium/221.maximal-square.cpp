/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 */

// @lc code=start
class Solution {
public:
  int maximalSquare(vector<vector<char>> &matrix) {
    if (matrix.empty())
      return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 0));
    int max_side = 0;
    for (int i = 0; i < rows; ++i) {
      dp[i][0] = matrix[i][0] - '0';
      max_side = max(max_side, dp[i][0]);
    }
    // printf("++ max_side: %d\n", max_side);
    for (int i = 0; i < cols; ++i) {
      dp[0][i] = matrix[0][i] - '0';
      max_side = max(max_side, dp[0][i]);
    }
    // printf("-- max_side: %d\n", max_side);
    for (int i = 1; i < rows; ++i) {
      for (int j = 1; j < cols; j++) {
        if (matrix[i][j] == '1') {
          dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
        } else {
          dp[i][j] = 0;
        }
        max_side = max(max_side, dp[i][j]);
        // printf("** max_side: %d\n", max_side);
      }
    }
    return max_side * max_side;
  }
};
// @lc code=end
