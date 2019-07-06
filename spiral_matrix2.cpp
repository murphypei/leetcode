#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> results(n, vector<int>(n));
        int m = n * n;
        int cnt = 1;
        for (int i = 0, k = n; i < k; ++i, --k)
        {
            for (int c = i; c < k; ++c)
            {
                results[i][c] = cnt++;
            }
            for (int r = i + 1; r < k; ++r)
            {
                results[r][k - 1] = cnt++;
            }
            for (int c = k - 2; c >= i; --c)
            {
                results[k - 1][c] = cnt++;
            }
            for (int r = k - 2; r > i; --r)
            {
                results[r][i] = cnt++;
            }
        }
        return results;
    }
};