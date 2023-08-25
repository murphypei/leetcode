/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i]表示s[0:i]是否可以被拆分
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            // dp[i] = dp[j] && s[j:i] in wordDict
            for (int j = i-1; j >= 0; --j) {
                if (dp[j]) {
                    string word = s.substr(j, i-j);
                    if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end()) {
                        dp[i] = true;
                        break;
                    }
                }
            }
        }
        return dp[s.size()];
    }
};
// @lc code=end

