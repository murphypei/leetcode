/**
 * 从1开始，将整数排成一个数列，看成字符串，求第n个字符的数字
 
Input:
11

Output:
0

Explanation:
The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.

*/

class Solution {
public:
    int findNthDigit(int n) {
        // len用来记录当前循环空间中，数字的位数
        // cnt用来记录当前循环空间中，有多少个数字
        // start用来记录当前循环空间中，起始的第一个数字
        long long len = 1, cnt = 9, start = 1;
        while(n > len * cnt)
        {
            n -= len * cnt;     // len * cnt表示当前循环空间中所有数字共有字符个数
            ++len;
            cnt *= 10; 
            start *= 10;
        }
        // 求第n个字符出现在哪个数字上
        start += (n - 1) / len;   // 此时n已经不是最初的n了，循环中减小了
        string t = to_string(start);
        return t[(n-1) % len] - '0';
    }
};
