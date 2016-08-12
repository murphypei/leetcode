// Given an integer n, return the number of trailing zeroes in n!.

// Note: Your solution should be in logarithmic time complexity.


/**
 * 思路：将n的阶乘分解因式, 在质数中, 2和5相乘才有可能出现0.
 * 因为2的个数大于5, 所以只需要考虑5的个数.
 * [重要]对于较大的数, 可能分解为多个5*5, 比如25中包含5*5所以还要计算25/5中的5的个数.
 */

class Solution {
public:
    int trailingZeroes(int n) {
        if(n < 1)
            return n;
        int res = 0;
        while(n >= 5) {
            res += n / 5;
            n /= 5;
        }
        return res;
    }
};