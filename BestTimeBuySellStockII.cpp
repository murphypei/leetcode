/**
 * 买卖股票的问题，给出的序列就是股票在不同时间的价值
 * 不同于买卖股票为问题1，可以交易多次
 *
 * 因为可以买卖多次，很明显的策略就是对任意两天差值大于0（后面的数减去前面的数）的都可以交易
 * 因此，实际问题就转换为了累加任意相邻两天差值大于0的和
 */

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <=1 )  
            return 0;  
        int res = 0;  
        for(int i = 0; i < prices.size() - 1; i++)  
        {  
            int diff = prices[i+1] - prices[i];  
            if(diff > 0)  
                res += diff;  
        }  
        return res;  
    }
};