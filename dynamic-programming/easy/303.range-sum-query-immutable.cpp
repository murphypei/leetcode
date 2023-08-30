/*
 * @lc app=leetcode id=303 lang=cpp
 *
 * [303] Range Sum Query - Immutable
 */

// @lc code=start
class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp = vector<int>(nums.size() + 1, 0);
        for (int i = 1; i <= nums.size(); i++) {
            dp[i] = dp[i - 1] + nums[i - 1];
        }
    }
    
    int sumRange(int left, int right) {
        return dp[right + 1] - dp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

