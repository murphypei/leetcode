#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 判断是否能够将其分为相同大小的组，组内元素还相同，因此本质上是求所有相同元素的最大公约数。
    bool hasGroupsSizeX(vector<int> &deck)
    {
        vector<int> count(10000, 0);
        for (auto elem : deck)
        {
            count[elem]++;
        }

        int g = -1;
        for (int i = 0; i < 10000; ++i)
        {
            if (count[i] > 0)
            {
                if (g == -1)
                {
                    g = count[i];
                }
                else
                {
                    g = gcd(g, count[i]);
                }
            }
        }
        return g >= 2;
    }

    // 采用辗转相减法求最大公约数
    int gcd(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
            {
                a = a - b;
            }
            else
            {
                b = b - a;
            }
        }
        return a;
    }
};

int main()
{
    Solution s;
    vector<int> a{1};
    std::cout << s.hasGroupsSizeX(a) << std::endl;
}