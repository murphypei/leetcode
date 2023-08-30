/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

// @lc code=start
class Solution {
public:
  string longestPalindrome(string s) {
    int beg = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
      // 以当前字符为中心的回文
      for (int j = 0; (i - j >= 0) && (i + j < s.size()); j++) {
        if (s[i - j] != s[i + j]) {
          break;
        }
        if ((2 * j + 1 > end - beg)) {
          beg = i - j;
          end = i + j + 1;
          //   printf("i:%d, beg: %d, end: %d\n", i, beg, end);
        }
      }

      // 以当前字符和其后的字符为中心的回文
      if (s[i] == s[i + 1]) {
        for (int j = 0; (i - j >= 0) && (i + j + 1 < s.size()); j++) {
          if (s[i - j] != s[i + j + 1]) {
            break;
          }
          if (2 * j + 2 > end - beg) {
            beg = i - j;
            end = i + j + 2;
          }
        }
      }
    }
    return s.substr(beg, end - beg);
  }
};
// @lc code=end
