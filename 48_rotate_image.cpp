#include <vector>

using namespace std;

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 先转置，然后行不动，列反转。
        int n = matrix.size();
        for (int i = 0; i < n; ++i) // row
        {
            for (int j = 0; i < n - j; ++j) // column
            {
                std::swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
            }
        }
        for (int i = 0; i < n / 2; ++i)
        {
            std::swap(matrix[i], matrix[n - 1 - i]);
        }
    }
};

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // 直接按照旋转公式旋转
        // 矩阵的四条边每个坐标都可以用顺时针的上一个位置表示，其中 [i][j] 顺时针旋转可以得到
        // [j][n-1-i]，将四个点带入计算。

        int n = matrix.size();
        int last, cur;
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i; j < n - i - 1; j++)
            {
                // 保存当前值，然后改变当前值
                cur = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                last = cur;

                // 根据公式, [j][n-1-i] 旋转得到 [n-1-i][n-1-j] （这里公式里的 i 就是 j，公式里的 j 就是 n-1-i）
                cur = matrix[n - 1 - i][n - 1 - j];
                matrix[n - 1 - i][n - 1 - j] = last;
                last = cur;

                cur = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = last;
                last = cur;

                matrix[i][j] = last;
            }
        }
    }
};