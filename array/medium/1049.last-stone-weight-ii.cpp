/*
 * @lc app=leetcode id=1049 lang=cpp
 *
 * [1049] Last Stone Weight II
 */

// @lc code=start
class Solution {
public:
  int lastStoneWeightII(vector<int> &stones) {
    // 需要转换思路，本质是求将数组分为两部分，两部分和的差最小。
    // target就是总和的一半，那么目标就是尽量靠近target而且不能超过target。
    // 可以按照0-1背包问题处理，如何能取得最大价值。
    int sum = accumulate(stones.begin(), stones.end(), 0);
    int target = sum / 2;

    // dp[i][j]表示从i到j的背包中能获得的最大值
    vector<vector<int>> dp(stones.size(), vector<int>(target + 1, 0));
    // target=0，那么dp一定也是0
    for (int i = 0; i < dp.size(); i++) {
      dp[i][0] = 0;
    }
    // 取0块石头，那么超过石头重量的背包容量就能放下，否则也是0
    for (int j = 0; j <= target; j++) {
      dp[0][j] = (j >= stones[0] ? stones[0] : 0);
    }
    
    for (int i = 1; i < stones.size(); i++) {
      for (int j = 0; j <= target; j++) {
        if (j < stones[i]) {
          dp[i][j] = dp[i - 1][j];
        } else {
          dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]);
        }
      }
    }
      // printf("sum: %d, target: %d, dp[target]: %d\n", sum, target,
      // dp[target]);
      return sum - dp[stones.size() - 1][target] * 2;
  }
};
// @lc code=end
