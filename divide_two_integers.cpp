#include <algorithm>
#include <limits>

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
        {
            sign = -1;
        }
        long res = 0;
        long remain = std::abs((long)dividend);
        long ldivisor = std::abs((long)divisor);
        while (true)
        {
            res += bitDivide(remain, ldivisor, &remain);
            if (remain < ldivisor)
            {
                break;
            }
        }
        if (sign < 0)
        {
            return -res < std::numeric_limits<int>::min() ? std::numeric_limits<int>::min() : -res;
        }
        else
        {
            return res > std::numeric_limits<int>::max() ? std::numeric_limits<int>::max() : res;
        }
    }

private:
    long bitDivide(long dividend, long divisor, long *remain)
    {
        if (dividend < divisor)
        {
            return 0;
        }
        long res = 1;
        *remain = dividend - divisor;
        while (true)
        {
            divisor <<= 1;
            if (divisor > dividend)
            {
                return res;
            }
            else
            {
                res <<= 1;
                *remain = dividend - divisor;
            }
        }
    }
};