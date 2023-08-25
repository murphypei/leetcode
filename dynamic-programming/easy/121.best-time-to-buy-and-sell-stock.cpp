/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 记录利润
        int min_price = prices[0];
        int best_profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            min_price = min(min_price, prices[i]);
            best_profit = max(best_profit, prices[i] - min_price);
        }
        return best_profit;
    }
};
// @lc code=end

