#include <string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int res = 0;
        auto it = s.rbegin();
        while (*it == ' ')
        {
            it++;
        }
        for (; it != s.rend(); ++it)
        {
            if (*it == ' ')
            {
                return res;
            }
            res++;
        }
        return res;
    }
};