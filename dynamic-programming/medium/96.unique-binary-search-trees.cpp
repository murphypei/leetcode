/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n <= 0) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        return numTrees(1, n);
    }

    int numTrees(int start, int end) {
        if (start >= end) {
            return 1;
        }
        int res = 0;
        for (int i = start; i <= end; i++) {
            int left = numTrees(start, i - 1);
            int right = numTrees(i + 1, end);
            res += left * right;
        }
        return res;
    }
};
// @lc code=end

