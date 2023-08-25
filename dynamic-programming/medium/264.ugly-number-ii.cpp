/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 */

// @lc code=start
class Solution {
public:
  int nthUglyNumber(int n) {
    if (n <= 3) {
        return n;
    }

    vector<int> ugly(n, 0);
    ugly[0] = 1;
    ugly[1] = 2;
    int p2 = 0, p3 = 0, p5 = 0;
    for (int i = 2; i < n; ++i) {
      while (ugly[p2] * 2 <= ugly[i - 1]) {
        p2++;
      }
      while (ugly[p3] * 3 <= ugly[i - 1]) {
        p3++;
      }
      while (ugly[p5] * 5 <= ugly[i - 1]) {
        p5++;
      }
      ugly[i] = min(min(ugly[p2] * 2, ugly[p3] * 3), ugly[p5] * 5);
    }
    return ugly[n - 1];
  }
};
// @lc code=end
