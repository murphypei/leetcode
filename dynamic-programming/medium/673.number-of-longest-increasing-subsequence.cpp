/*
 * @lc app=leetcode id=673 lang=cpp
 *
 * [673] Number of Longest Increasing Subsequence
 */

// @lc code=start
class Solution {
public:
  int findNumberOfLIS(vector<int> &nums) {
    vector<int> dp_cnt(nums.size(), 1);
    vector<int> dp_len(nums.size(), 1);

    int max_len = 0;
    int cnt_res = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < i; ++j) {
        if (nums[i] <= nums[j]) {
          continue;
        }
        // nums[i] > nums[j]
        if (dp_len[i] == dp_len[j] + 1) {
          // 长度一致，则相加
          dp_cnt[i] += dp_cnt[j];
        } else if (dp_len[i] < dp_len[j] + 1) {
          // 当前子序列比其他子序列长度短，则更新
          dp_cnt[i] = dp_cnt[j];
          dp_len[i] = dp_len[j] + 1;
        }
      }

      if (dp_len[i] > max_len) {
        max_len = dp_len[i];
        cnt_res = dp_cnt[i];
      } else if (dp_len[i] == max_len) {
        cnt_res += dp_cnt[i];
      }
    }

    return cnt_res;
  }
};
// @lc code=end
