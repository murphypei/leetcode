#include <vector>

using namespace std;

class Solution
{
public:
    int surfaceArea(vector<vector<int>> &grid)
    {
        int dr[]{0, 1, 0, -1};
        int dc[]{1, 0, -1, 0};

        int N = grid.size();
        int ans = 0;

        // 对每个网格，单独求每个柱子的表面积：4个侧面 + 2个底面
        // 侧面面积可以用高度减去和相邻柱子的重叠面积：max(grid[r][c] - nv, 0)
        for (int r = 0; r < N; ++r)
        {
            for (int c = 0; c < N; ++c)
            {
                if (grid[r][c] > 0)
                {
                    ans += 2;
                    for (int k = 0; k < 4; ++k)
                    {
                        int nr = r + dr[k];
                        int nc = c + dc[k];
                        int nv = 0;
                        if (0 <= nr && nr < N && 0 <= nc && nc < N)
                            nv = grid[nr][nc];

                        ans += max(grid[r][c] - nv, 0);
                    }
                }
            }
        }
        return ans;
    }
};
