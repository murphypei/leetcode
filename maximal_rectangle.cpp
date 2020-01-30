#include <vector>

using namespace std;

class Solution
{
public:
    int maximalRectangle(vector<vector<char>> &matrix)
    {
        int res = 0;
        const int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        const int n = matrix[0].size();
        if (n == 0)
        {
            return 0;
        }

        vector<int> left(n, 0), right(n, n), height(n, 0);

        for (int i = 0; i < m; ++i)
        {
            int cur_left = 0, cur_right = n; // cur_left 表示当前行的最左边, cur_right 是最右边

            for (int j = 0; j < n; ++j)
            {
                height[j] = matrix[i][j] == '1' ? height[j] + 1 : 0; // 则 height++, 否则为 0
            }

            for (int j = 0; j < n; ++j)
            {
                // 考虑上一行的左边界，取最靠右的（较大的）
                left[j] = matrix[i][j] == '1' ? max(left[j], cur_left) : 0;
                cur_left = matrix[i][j] == '1' ? cur_left : j + 1;
            }

            for (int j = n - 1; j >= 0; --j)
            {
                // 考虑上一行的右边界，取最靠左的（较小的）
                right[j] = matrix[i][j] == '1' ? min(right[j], cur_right) : n;
                cur_right = matrix[i][j] == '1' ? cur_right : j;
            }

            for (int j = 0; j < n; ++j)
            {
                res = max(res, (right[j] - left[j]) * height[j]); // 计算面积
            }
        }
        return res;
    }
};