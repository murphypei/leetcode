#include <iostream>
#include <vector>

class Solution
{
public:
    int numTrees(int n)
    {
        std::vector<int> dp(n + 1, 0);
        dp[0] = 1; // 空树只有一种可能（而不是 0）
        dp[1] = 1; // 只有根节点也只有一种可能。

        for (int i = 2; i <= n; ++i)
        {
            // 求 2~n 的结果。迭代的写法，省去了递归。
            for (int j = 1; j <= i; ++j)
            {
                // 每个 i 的结果是 1~i 之间所有不同 j 为根的节点数目的和。
                dp[i] += dp[j - 1] * dp[i - j]; // 这个公式表示一个节点的数目是左右子树数目的乘乘积。
            }
        }

        return dp[n];
    }
};

int main()
{
    Solution s;
    std::cout << s.numTrees(3) << std::endl;
}