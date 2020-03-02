class Solution
{
public:
    // 动态规划，斐波那契数列
    int climbStairs(int n)
    {
        if (n <= 2)
        {
            return n;
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