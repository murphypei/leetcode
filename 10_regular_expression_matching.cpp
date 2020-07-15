#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        int m = s.size(), n = p.size();
        // dp[i][j] 表示 s 的前 i 个字符和 p 的前 j 个字符匹配。
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        dp[0][0] = true;
        for (int i = 0; i <= m; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                // 要注意，dp 里面的下标值比 s 和 p 中的值大 1.
                if (j > 1 && p[j - 1] == '*')
                {
                    // 匹配符为'*'有两种情况：

                    // 1. 将前一个字符（p[j-2]）作为出现0次消除掉：则dp[i][j] = dp[i][j - 2]，s[i-1] 和 p[j-3]
                    // 匹配，p[j-2]和p[j-1]被当作空了。

                    // 2. 和前一个字符一起，需要p[j-2]和s[i-1]相等，前一个字符和'*'连在一起作为多次出现。
                    // dp[i-1][j] 表示 s[i-2] 和 p[j-1] 匹配，因为 p[j-1] 是 '*'，因此如果此时 s[i-1]==p[j-2]，或者
                    // p[s-2]=='.'，都可以把 p[i-1] 上的 '*' 作为重复前面的字符来处理。
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