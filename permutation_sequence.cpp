#include <algorithm>
#include <string>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        string res(n, '1');
        for (int i = 0; i < n; ++i)
        {
            res[i] += i;
        }
        for (int i = 1; i < k; ++i)
        {
            nextPermutation(res);
        }
        return res;
    }

    void nextPermutation(string &s)
    {
        int k = -1;
        for (int i = 0; i < s.size() - 1; ++i)
        {
            if (s[i] < s[i + 1])
            {
                k = i;
            }
        }
        if (k < 0)
        {
            std::reverse(s.begin(), s.end());
        }
        else
        {
            for (int i = s.size() - 1; i > k; --i)
            {
                if (s[i] > s[k])
                {
                    std::swap(s[i], s[k]);
                    break;
                }
            }
            std::reverse(s.begin() + k + 1, s.end());
        }
    }
};