/**
 * 给定一个数n，求1 + 2 + 3 + ... + i <= n的最大i值
 *
 * 注意大整数越界问题
 */
 
class Solution {
public:
    int arrangeCoins(int n) {
        if(!n)
            return 0;
        long sum = 0;   // 必须用long来防止整数越界
        int i = 1;
        for(; i <= n; ++i)
        {
            sum += i;
            if(sum >= (long)n)
                break;
        }
        return sum == (long)n ? i : i - 1;
    }
};
