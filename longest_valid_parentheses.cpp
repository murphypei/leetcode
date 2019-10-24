#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        int res = 0, n = s.size();
        vector<int> dp(n + 1); // dp[i] respresent the longest valid length of the string ending in s[i-1].
        for (int i = 1; i <= n; ++i)
        {
            int j = i - 2 - dp[i - 1]; // the nearest character pos out of the valid substring.
            if (s[i - 1] == '(' || j < 0 || s[j] == ')')
            {
                dp[i] = 0;
            }
            else
            {
                dp[i] = dp[i - 1] + 2 + dp[j];
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};