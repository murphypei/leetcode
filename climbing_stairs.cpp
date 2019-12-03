class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        if (n == 2)
        {
            return 2;
        }
        int a = 1, b = 2, r;
        for (int i = 3; i <= n; ++i)
        {
            r = a + b;
            a = b;
            b = r;
        }
        return r;
    }
};