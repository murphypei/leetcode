// Calculate the sum of two integers a and b, 
// but you are not allowed to use the operator + and -.

// Example:
// Given a = 1 and b = 2, return 3.

#include <iostream>
#include <cstdio>

/**
 * 思路：利用计算机做加法的原理, 做半加法, 先按位与得到各个位的进位, 然后按位异或得到各个位计算结果
 * 将进位和各个位计算结果相加即可(注意得到的进位需要左移之后相加)
 */
class Solution {
public:
    int getSum(int a, int b) {
        int carry = a & b;
        int result = a ^ b;
        if(!carry) 
            return result;
        else
            return getSum(result, carry << 1);
    }
};


int main() {
    Solution s;
    std::cout << s.getSum(5, 11) << std::endl;
    
    getchar();
    return 0;
}