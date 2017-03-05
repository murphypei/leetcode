/**
Given a positive integer, output its complement number. The complement strategy is to flip the bits of its binary representation.

Note:
The given integer is guaranteed to fit within the range of a 32-bit signed integer.
You could assume no leading zero bit in the integer’s binary representation.
Example 1:
Input: 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
Example 2:
Input: 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

*/

// 求二进制位的补数
// bitset中有flip()可以直接求所有位的翻转，但是题目的要求本质上是从最高有效位开始翻转，之前的0位不能翻转
// 所以需要手动找到最高有效位然后开始翻转。
// bitset对象的[pos]从低位向高位存储，也就是numbs[0]是最低位
// bitset的to_ulong能够直接返回一个unsigned long整型。



class Solution {
public:
    int findComplement(int num) {
        bitset<32> numbs(num);
        bool startFlip = false;
        
        for (int i = 31; i >= 0; --i) {
            if (numbs[i] > 0) {
                startFlip = true;
            }
            if (startFlip) {
                numbs[i] = 1 - numbs[i];
            }
        }
        
        return numbs.to_ulong();
    }
    
};