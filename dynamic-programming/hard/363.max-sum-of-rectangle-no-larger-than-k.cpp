/*
 * @lc app=leetcode id=363 lang=cpp
 *
 * [363] Max Sum of Rectangle No Larger Than K
 */

// @lc code=start
class Solution {
public:
  int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
    int res = INT_MIN;
    int m = matrix.size();
    int n = matrix[0].size();
    // 枚举上边界
    for (int i = 0; i < m; i++) {
      // sum保存的是在一个上下边界内，每一列元素的和
      vector<int> sum(n, 0);
      // 枚举下边界
      for (int j = i; j < m; j++) {
        // 边界内列元素求和
        for (int c = 0; c < n; c++) {
          sum[c] += matrix[j][c];
        }

        // 表示的是一维数组中，到当前位置的数组和
        vector<int> subSum(n + 1, 0);
        for (int c = 0; c < n; c++) {
          subSum[c + 1] = sum[c] + subSum[c];
          // 因为要求数组和不超过k，所以对于当前的s来说，
          // 应该找一个之前的数组和s'，使得s-k>s'
          // 这里可以利用set之类的数据结构优化成二分查找。
          for (int n = 0; n <= c; n++) {
            if (subSum[c + 1] - subSum[n] <= k) {
              res = max(res, subSum[c + 1] - subSum[n]);
            }
          }
        }
      }
    }
    return res;
  }
};
// @lc code=end
