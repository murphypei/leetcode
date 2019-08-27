#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // dp[i][j] 表示 s[0~i] 和 p[0~j] 匹配。
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                if (j > 1 && p[j - 1] == '*')
                {
                    // 匹配符为'*'有两种情况：
                    // 1. 将前一个字符作为出现0次消除掉：则dp[i][j] = dp[i][j - 2]
                    // 2. 和前一个字符一起，需要p[j-2]和s[i-1]相等，前一个字符和'*'连在一起作为多次出现。
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
                }
                else
                {
                    // 如果匹配符不是'*'，则必须完全匹配或者为'.'。
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
                }
            }
        }
        return dp[m][n];
    }
};