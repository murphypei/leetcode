#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string compressString(string S)
    {
        if (S.size() <= 1)
        {
            return S;
        }
        string res;
        char prev = S[0];
        size_t cnt = 1;
        for (size_t i = 1; i < S.size(); ++i)
        {
            if (S[i] == prev)
            {
                cnt++;
            }
            else
            {
                res += prev;
                res += std::to_string(cnt);
                prev = S[i];
                cnt = 1;
            }
        }
        res += prev;
        res += std::to_string(cnt);
        return res.size() >= S.size() ? S : res;
    }
};

int main()
{
    Solution s;
    std::cout << s.compressString("aabcccccaa") << std::endl;
}