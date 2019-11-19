#include <string>

class Solution
{
public:
    bool isMatch(std::string s, std::string p)
    {
        int s_star = -1, p_star = -1;
        int si = 0, pi = 0;
        while (si < s.size())
        {
            if (pi < p.size() && (s[si] == p[pi] || p[pi] == '?'))
            {
                pi++;
                si++;
            }
            else if (p[pi] == '*')
            {
                p_star = pi;
                s_star = si;
                // the si will not be updated because star can match empty
                pi++;
            }
            else if (s_star >= 0)
            {
                si = ++s_star;
                // !!!important: pi back to the next of p_star
                pi = p_star + 1;
            }
            else
            {
                return false;
            }
        }
        // after match all charaters of s, p must only have star character
        while (pi < p.size() && p[pi] == '*')
        {
            pi++;
        }
        return pi == p.size();
    }
};