#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // 动态规划
    int minDistance(string word1, string word2)
    {
        int m = word1.size();
        int n = word2.size();
        // d[i][j] 表示 word1 的前 i 个字符和 word2 的前 j 个字符之间的编辑距离。
        vector<vector<int>> d(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; ++i)
        {
            d[i][0] = i;
        }
        for (int i = 1; i <= n; ++i)
        {
            d[0][i] = i;
        }
        for (int i = 1; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // 注意 word1[i-1] 表示第 i 个字符，也就是当前字符相等，则标记距离不变
                if (word1[i - 1] == word2[j - 1])
                {
                    d[i][j] = d[i - 1][j - 1];
                }
                else
                {
                    // d[i-1][j-1] 表示改变某个字符串中的当前字符，d[i-1][j] 和 d[i][j-1]
                    // 则表示删除或者插入某个字符，取三者最小的编辑距离 + 1
                    d[i][j] = std::min(d[i - 1][j - 1], std::min(d[i][j - 1], d[i - 1][j])) + 1;
                }
            }
        }
        return d[m][n];
    }
};