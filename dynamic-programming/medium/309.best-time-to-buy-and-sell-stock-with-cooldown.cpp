/*
 * @lc app=leetcode id=309 lang=cpp
 *
 * [309] Best Time to Buy and Sell Stock with Cooldown
 */

// @lc code=start
class Solution {
public:
  int maxProfit(vector<int> &prices) {
    // https://blog.csdn.net/zjuPeco/article/details/76468185
    if (prices.size() <= 1) {
      return 0;
    }
    int s0 = 0;
    int s1 = -prices[0];
    int s2 = INT_MIN;
    for (int i = 1; i < prices.size(); i++) {
      int t0 = s0;
      int t1 = s1;
      int t2 = s2;
      s0 = max(t0, t2);
      s1 = max(t0 - prices[i], t1);
      s2 = t1 + prices[i];
    }
    return max(s0, s2);
  }
};
// @lc code=end
