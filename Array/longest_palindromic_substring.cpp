#include <string>
#include <vector>

using namespace std;

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
        std::vector<std::vector<bool>> status(n, std::vector<bool>(n, false));
        int max_len = 0;
        int beg = 0, end = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j <= i; ++j)
            {
                if ((i == j) || (i == j + 1 && s[i] == s[j]) || (s[i] == s[j] && i > 0 && j < n - 1 && status[j + 1][i - 1]))
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