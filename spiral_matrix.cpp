#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        if (matrix.empty())
        {
            return results;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();
        int rbegin = 0, rend = rows, cbegin = 0, cend = cols;
        for (; rbegin < rend || cbegin < cend; ++rbegin, --rend, ++cbegin, --cend)
        {
            // print row
            if (rbegin < rend)
            {
                for (int i = cbegin; i < cend; ++i)
                {
                    results.push_back(matrix[rbegin][i]);
                }
            }
            // print column
            if (cbegin < cend)
            {
                for (int i = rbegin + 1; i < rend; ++i)
                {
                    results.push_back(matrix[i][cend - 1]);
                }
            }
            // print row
            if (rbegin < rend - 1)
            {
                for (int i = cend - 2; i >= cbegin; --i)
                {
                    results.push_back(matrix[rend - 1][i]);
                }
            }
            // print column
            if (cbegin < cend - 1)
            {
                for (int i = rend - 2; i > rbegin; --i)
                {
                    results.push_back(matrix[i][cbegin]);
                }
            }
        }
        return results;
    }

private:
    vector<int> results;
};