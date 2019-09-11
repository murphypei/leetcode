#include <string>

using namespace std;

class Solution
{
public:
    int countSubstrings(string s)
    {
        // 这个解法的思路是以某一（或两）个元素为中间值，然后找寻其分别向两边扩展的子串是否为回文。
        // 以一个元素为中间值的子串长度为奇数，以两个元素为中间值的长度为偶数。

        int n = s.length(), res = 0, l, r;
        // odd length substrings
        for (int i = 0; i < n; i++)
        {
            // i is the mid of the substring
            l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                res++;
                l--;
                r++;
            }
        }
        // even length substrings
        for (int i = 0; i < n - 1; i++)
        {
            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                res++;
                l--;
                r++;
            }
        }
        return res;
    }
};