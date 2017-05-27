/**
 * 买卖股票的问题，给出的序列就是股票在不同时间的价值
 * 不同于买卖股票为问题1(交易一次)和问题2(交易无数次)，最多交易两次
 *
 * 因为买卖次数的限制是最多，而不是固定，所以用动态规划来求解
 * http://blog.csdn.net/linhuanmars/article/details/23236995
 */

#include <vector>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
            return 0;

        // 可以求最多进行k次交易的结果
        const int k = 2;
        const int n = prices.size();
        int g[n][k + 1] = {0};
        int l[n][k + 1] = {0};

        for (int i = 1; i < n; ++i)
        {
            int diff = prices[i] - prices[i - 1];
            for (int j = 1; j <= k; ++j)
            {
                // 动态规划递推公式
                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                g[i][j] = max(l[i][j], g[i - 1][j]);
            }
        }
        return g[n - 1][k];
    }
};