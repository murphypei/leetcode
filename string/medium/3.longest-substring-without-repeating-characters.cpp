/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int                           head = 0, tail = 0, max_len = 0;
        std::unordered_map<char, int> temp;
        while (tail < s.size())
        {
            // 当前字符已经在 temp 中，更新 head 位置（head 位置为当前字符上一次出现的位置 + 1）
            auto it = temp.find(s[tail]);
            if (it != temp.end())
            {
                head = std::max(it->second + 1, head);
            }
            // 更新当前字符的位置
            temp[s[tail]] = tail;
            // 更新最大长度
            max_len = std::max(max_len, tail - head + 1);
            ++tail;
        }
        return max_len;
    }
};
// @lc code=end
