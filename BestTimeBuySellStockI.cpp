/**
 * 买卖股票的问题，给出的序列就是股票在不同时间的价值，寻找一次交易（买和卖）可以获得的最大利润
 * 可以转换为在一个序列中，寻找后面的数比前面的数差值最大的最优解问题
 *
 * 动态规划的思想：保存两个变量，一个局部最优解，一个全局最优解。
 * 在第i步，局部最优解必须包含当前元素nums[i]
 */

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() <= 1)
        {
            return 0;
        }
        int globalMax = 0;
        int localMax = 0;
        for (int i = 1; i < prices.size(); ++i)
        {
            // 动态规划的递推公式
            /*
            * 局部最优解必须包含当前元素，则只有两种可能:
            * 在第i天卖出股票，则当前的局部最优是：今天的价格 - 前一天的价格 + 前一天的局部最优
            *     localMax + prices[i] - prices[i-1]
            * 在当前天不卖出股票，则为: 0
            */
            localMax = std::max(localMax + prices[i] - prices[i-1], 0);
            globalMax = std::max(globalMax, localMax);
        }

        return globalMax;
    }
};

int main(int args, char *argv[])
{
    shared_ptr<Solution> sptr = make_shared<Solution>();
    vector<int> vec{7, 1, 5, 3, 6, 4};
    cout << sptr->maxProfit(vec) << endl;

    getchar();
    return 0;
}
