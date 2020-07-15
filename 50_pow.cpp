#include <iostream>

class Solution
{
public:
    double myPow(double x, int n)
    {
        return myPowHelp(x, n);
    }

private:
    double myPowHelp(double x, long n)
    {
        if (n < 0)
        {
            return 1.0 / myPowHelp(x, -n);
        }
        double result = 1;
        int valid = 1;
        while (n != 0)
        {
            // 当前最低位（0或者1)
            valid = n % 2;
            if (valid != 0)
            {
                result *= x;
            }
            x *= x;
            n >>= 1;
        }
        return result;
    }
};

int main(int argc, char *argv[])
{
    Solution s;
    std::cout << s.myPow(2, 10) << std::endl;
    std::cout << s.myPow(2, -3) << std::endl;
}