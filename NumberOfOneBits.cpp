// Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

// For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.


/**
 * 思路：n%2判断最后一位是否是1，然后右移一位，继续判断
 */
 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n) {
            if(n % 2) {
                ++count;
            }
            n = n >> 1;     // 或者是n /= 2;
        }
        return count;
    }
};