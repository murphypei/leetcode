#include <vector>

using namespace std;

class Solution
{
public:
    // 动态规划，到达每个点的最小值就是其左边和上面到达当前点的最小值。
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.empty() || grid[0].empty())
        {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        long long sum[m][n];
        sum[0][0] = grid[0][0];

        for (int i = 1; i < n; ++i)
        {
            sum[0][i] = grid[0][i] + sum[0][i - 1];
        }

        for (int i = 1; i < m; ++i)
        {
            sum[i][0] = grid[i][0] + sum[i - 1][0];
        }

        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                sum[i][j] = std::min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
            }
        }
        return sum[m - 1][n - 1];
    }
};