#include <limits>
#include <vector>

using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> dp(amount + 1, amount + 1); // 每个金额可以需要的最少零钱数目。
        dp[0] = 0;

        // 求 1~n 中间每个总金额可以被最少表示的零钱数目，后面的金额可以复用前面的金额。
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < coins.size(); ++j)
            {
                if (coins[j] <= i)
                {
                    dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
                }
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};
