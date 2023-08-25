/*
 * @lc app=leetcode id=368 lang=cpp
 *
 * [368] Largest Divisible Subset
 */

// @lc code=start
class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int> &nums) {
    // 必须先排序处理
    std::sort(nums.begin(), nums.end());

    vector<int> dp(nums.size(), 1);
    int max_idx = 0;
    // 先找到包含nums[i]的最大子集，保留最大子集长度所在的index
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; j++) {
        if (nums[i] % nums[j] == 0) {
          dp[i] = std::max(dp[i], dp[j] + 1);
        }
      }
      if (dp[i] > dp[max_idx]) {
        max_idx = i;
      }
    }

    // 通过最大子集的最大元素，逐步迭代向前寻找所有的元素。
    // 这里必须要注意，仅仅是能被最大元素整除这个条件是不满足的。
    int sub_len = dp[max_idx];
    vector<int> ans(sub_len, 0);
    ans[--sub_len] = nums[max_idx];
    int last_max_idx = max_idx;
    for (int i = max_idx - 1; i >= 0 && sub_len > 0; i--) {
      if (nums[last_max_idx] % nums[i] == 0 && dp[i] == sub_len) {
        ans[--sub_len] = (nums[i]);
        last_max_idx = i;
      }
    }
    return ans;
  }
};
// @lc code=end
