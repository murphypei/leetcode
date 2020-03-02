#include <limits>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    string minWindow(string s, string t)
    {
        unordered_map<char, int> targets;
        for (auto &c : t)
        {
            targets[c]++;
        }
        int left = 0;      // 滑动窗口左边界
        int found_cnt = 0; // 窗口中包含的目标字符个数
        int substr_start = 0, substr_len = s.size() + 1;

        for (int right = 0; right < s.size(); ++right)
        {
            // 如果 s[right] 不在target 中，targets[s[right]] = 0，减一之后应该小于 0，所以大于等于 0 的是在 t
            // 中的字符。
            if (--targets[s[right]] >= 0)
            {
                found_cnt++;
            }

            // 如果全部找到，缩小左边界，更新记录，否则什么都不用做，继续扩大右边界即可。
            while (found_cnt == t.size())
            {
                // 更新记录
                if (substr_len > (right - left + 1))
                {
                    substr_len = right - left + 1;
                    substr_start = left;
                }
                // 缩小左边界。注意到，right 是减去计数，left 是增加，如果 targets 中本身不存在，则在
                // left <= right 是，此时的 targets[s[left]] 一定是小于 0 的。
                if (++targets[s[left]] > 0)
                {
                    found_cnt--;
                }
                left++;
            }
        }
        return substr_len == s.size() + 1 ? "" : s.substr(substr_start, substr_len);
    }
};