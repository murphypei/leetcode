/*
The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, calculate the Hamming distance.
*/

// 求两个整数的汉明距离，也就是二进制形式不同的位数
// 使用bitset，统计异或结果中1的个数就行了

class Solution {
public:
    int hammingDistance(int x, int y) {
        bitset<32> xbs(x);
        bitset<32> ybs(y);
        xbs ^= ybs;

        return xbs.count();
    }
};