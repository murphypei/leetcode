/**
 * 实现开平方
 */

// 利用二分查找法，也可以利用牛顿法
class Solution {
public:
    int mySqrt(int x) {
        long long low = 0;
        long long high = x / 2 + 1;
        while(low <= high)
        {
            long long mid = low + (high - low) / 2;
            long long sq = mid * mid;
            if(sq == x)
            {
                return mid;
            }
            else if(sq > x)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return high;  // 为什么是return high而不是low ???
    }
