/*
 * @lc app=leetcode id=198 lang=cpp
 *
 * [198] House Robber
 */

// @lc code=start
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int best = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i == 0) {
                dp[i] = nums[i];
            }
            else if (i == 1) {
                dp[i] = max(nums[i], dp[i - 1]);
            }
            else {
                dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
            }
            best = max(best, dp[i]);
        }
        return best;
    }
};
// @lc code=end

