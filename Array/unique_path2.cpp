#include <vector>

using namespace std;

class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        if (obstacleGrid.empty())
        {
            return 0;
        }
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (m == 1)
        {
            for (int i = 0; i < n; ++i)
            {
                if (obstacleGrid[0][i] == 1)
                {
                    return 0;
                }
            }
            return 1;
        }
        if (n == 1)
        {
            for (int i = 0; i < m; ++i)
            {
                if (obstacleGrid[i][0] == 1)
                {
                    return 0;
                }
            }
            return 1;
        }
        long long board[m][n];
        for (int i = 0; i < m; ++i)
        {
            if (obstacleGrid[i][0] == 0)
            {
                board[i][0] = 1;
            }
            else
            {
                for (int ii = i; ii < m; ++ii)
                {
                    board[ii][0] = 0;
                }
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (obstacleGrid[0][i] == 0)
            {
                board[0][i] = 1;
            }
            else
            {
                for (int ii = i; ii < n; ++ii)
                {
                    board[0][ii] = 0;
                }
                break;
            }
        }
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    board[i][j] = 0;
                }
                else
                {
                    board[i][j] = board[i - 1][j] + board[i][j - 1];
                }
            }
        }
        return board[m - 1][n - 1];
    }
};