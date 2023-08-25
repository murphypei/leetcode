/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // 关键在于理解负数的影响，只需要同时维护最大和最小值即可
        vector<int> max_dp(nums.size(), 0);
        vector<int> min_dp(nums.size(), 0);
        max_dp[0] = nums[0];
        min_dp[0] = nums[0];
        int max_res = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            max_dp[i] = max(max(max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]), nums[i]);
            min_dp[i] = min(min(max_dp[i - 1] * nums[i], min_dp[i - 1] * nums[i]), nums[i]);
            max_res = max(max_res, max_dp[i]);
        }
        return max_res;
    }
};
// @lc code=end

