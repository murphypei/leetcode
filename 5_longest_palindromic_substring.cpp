#include <string>
#include <vector>

using namespace std;

// 动态规划
class Solution
{
public:
    string longestPalindrome(string s)
    {
        if (s.size() < 1)
        {
            return s;
        }
        int n = s.size();
        // status[j][i] 表示以 j 开始，以 i 结尾的字串是否构成回文子串
        std::vector<std::vector<bool>> status(n, std::vector<bool>(n, false));
        int max_len = 0;
        int beg = 0, end = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if ((i == j) || (i == j + 1 && s[i] == s[j]) ||
                    (s[i] == s[j] && i > 0 && j < n - 1 && status[j + 1][i - 1]))
                {
                    status[j][i] = true;
                    if (max_len < i - j + 1)
                    {
                        max_len = i - j + 1;
                        beg = j;
                        end = i;
                    }
                }
                else
                {
                    status[j][i] = false;
                }
            }
        }
        return s.substr(beg, end - beg + 1);
    }
};

// 中心扩展
class Solution1
{
    string longestPalindrome(string s)
    {
        if (s.size() < 1)
        {
            return s;
        }
        // 子串位置，beg 是起始位置，end 是结束位置。
        int beg = 0, end = 0;
        // 以每个字符（奇数）或者每个字符和相邻字符（偶数）分别求可扩展的回文长度，遍历所有字符
        for (int i = 0; i < s.size(); ++i)
        {
            int len1 = expand(s, i, i);     // 以当前字符为中心。
            int len2 = expand(s, i, i + 1); // 以当前字符和相邻字符为中心。
            int len = len1 > len2 ? len1 : len2;
            if (len > (end - beg + 1))
            {
                beg = i - (len - 1) / 2;
                end = i + len / 2; // 如果是奇数回文，则 len/2==(len-1)/2，如果是偶数回文，则相当于i+1+(len-1)/2
            }
        }
        return s.substr(beg, (end - beg) + 1);
    }

    // 寻找最大扩展的回文，返回长度
    int expand(string &s, int left, int right)
    {
        int l = left, r = right;
        while (l >= 0 && r < s.size() && s[l] == s[r])
        {
            l--;
            r++;
        }
        // 这里要注意，如果 s[l] != s[r]，则长度为 r-l-1，如果 r 超过范围，则为 r-1-l，如果 l<0，则就是
        // r-(l+1)，因此返回都是 r-l-1.
        return r - l - 1;
    }
};