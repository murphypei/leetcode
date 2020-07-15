#include <vector>

using namespace std;

#include <vector>

using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int ans = 0;
        if (grid.empty())
        {
            return ans;
        }
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++j)
            {
                ans = std::max(ans, area(grid, i, j));
            }
        }
        return ans;
    }

    int area(vector<vector<int>> &grid, int c, int r)
    {
        if (c < 0 || r < 0 || c >= grid.size() || r >= grid[0].size() || grid[c][r] == 0)
        {
            return 0;
        }
        // 将遍历过的节点设置为 0，可以排除这些点。
        grid[c][r] = 0;
        int ans = 1;
        for (int i = 0; i < row_offsets.size(); ++i)
        {
            ans += area(grid, r + row_offsets[i], c + col_offsets[i]);
        }
        return ans;
    }

private:
    vector<int> row_offsets{-1, 1, 0, 0};
    vector<int> col_offsets{0, 0, 1, -1};
};