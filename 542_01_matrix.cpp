#include <map>
#include <queue>
#include <vector>

using namespace std;

class Solution
{
private:
    vector<int> rowOffsets{0, 0, -1, 1};
    vector<int> colOffsets{1, -1, 0, 0};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            return vector<vector<int>>();
        }
        vector<vector<int>> result(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<bool>> traversed(matrix.size(), vector<bool>(matrix[0].size(), false));

        queue<pair<int, int>> bfsQueue;
        // find all zero position
        for (int i = 0; i < matrix.size(); ++i)
        {
            for (int j = 0; j < matrix[i].size(); ++j)
            {
                if (matrix[i][j] == 0)
                {
                    bfsQueue.emplace(i, j);
                    traversed[i][j] = true;
                }
            }
        }

        // BFS
        while (!bfsQueue.empty())
        {
            auto p = bfsQueue.front();
            bfsQueue.pop();
            for (int k = 0; k < 4; ++k)
            {
                int i = p.first + rowOffsets[k];
                int j = p.second + colOffsets[k];
                if (i >= 0 && j >= 0 && i < matrix.size() && j < matrix[i].size() && !traversed[i][j])
                {
                    result[i][j] = result[p.first][p.second] + 1;
                    traversed[i][j] = true;
                    bfsQueue.emplace(i, j);
                }
            }
        }
        return result;
    }
};