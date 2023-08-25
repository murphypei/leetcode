/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 */

// @lc code=start
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0 ) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int res = 10, cur = 9;
        // 因为有0，所以从低位开始一位一位的看，确定了一位，前面一位的选择则变少一个
        // 本质是排列组合
        for (int i = 0; i < n - 1; i++) {
            cur *= (9 - i);
            res += cur;
        }
        return res;
    }
};
// @lc code=end

