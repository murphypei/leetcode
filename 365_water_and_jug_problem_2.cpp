#include <iostream>

class Solution
{
public:
    // 数学公式解法，z 必须是 x，y 的最大公约数的倍数
    bool canMeasureWater(int x, int y, int z)
    {
        if (x + y < z)
        {
            return false;
        }
        if (x == 0 || y == 0)
        {
            return z == 0 || x + y == z;
        }
        return z % gcd(x, y) == 0;
    }

    int gcd(int x, int y)
    {
        int r;
        while (x != y)
        {
            if (x > y)
            {
                r = x - y;
                x = y;
                y = r;
            }
            else
            {
                r = y - x;
                y = r;
            }
        }
        return x;
    }
};

int main()
{
    Solution s;
    std::cout << s.gcd(100, 24) << std::endl;
    std::cout << s.canMeasureWater(3, 5, 4) << std::endl;
}