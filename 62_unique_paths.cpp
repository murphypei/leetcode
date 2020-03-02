class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        // 动态规划，到达每个点的路线等于其上面和左边点路线的和，和斐波那契数列类似
        if (m <= 1 || n <= 1)
        {
            return 1;
        }
        int board[m][n];
        // 初始化第一列
        for (int i = 0; i < m; ++i)
        {
            board[i][0] = 1;
        }
        // 初始化第一行
        for (int i = 0; i < n; ++i)
        {
            board[0][i] = 1;
        }
        // 动态求解
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                board[i][j] = board[i - 1][j] + board[i][j - 1];
            }
        }
        return board[m - 1][n - 1];
    }
};