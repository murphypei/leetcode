// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.


// 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> status_vecs(s.size(), vector<bool>(s.size(), false));
        int max_palindrome_start = 0;
        int max_palindrome_len = 0;
        // status_vecs[j][i]表示s[j]到s[i]是否是一个回文字符串
        for(int i = 0; i < s.size(); ++i) {
            for(int j = 0; j <= i; ++j) {
                if(i - j < 2) {
                    status_vecs[j][i] = (s[i] == s[j]);
                }
                else {
                    status_vecs[j][i] = (s[j] == s[i] && status_vecs[j+1][i-1]);
                }

                // 更新最长回文的起点和长度
                if(status_vecs[j][i] && i - j + 1 > max_palindrome_len) {
                    max_palindrome_len = i - j + 1;
                    max_palindrome_start = j;
                }
            }
        }
        return s.substr(max_palindrome_start, max_palindrome_len);
    }
};