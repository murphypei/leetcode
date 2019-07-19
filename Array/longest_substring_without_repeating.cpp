#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        if (n == 0)
            return 0;
        unordered_map<char, int> m;
        int left = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            m[s[i]]++;
            while (m[s[i]] > 1)
            {
                m[s[left++]]--;
            }
            len = max(len, i - left + 1);
        }
        return len;
    }
};
