// Given an integer (signed 32 bits), write a function to check whether it is a power of 4.

// Example:
// Given num = 16, return true. Given num = 5, return false.

// Follow up: Could you solve it without loops/recursion?

// Credits:
// Special thanks to @yukuairoy for adding this problem and creating all test cases.

// Subscribe to see which companies asked this question



// 思路：
// 不用循环相除，4是2的倍数，所以可以用二进制位比较来判断
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num < 4 && num != 1)
            return false;
        bitset<32> bnum(num);
        if(bnum.count() > 1)
            return false;
        for(int i = 0; i < 32; ++i)
        {
            cout << bnum[i];
            if(i % 2 != 0 && bnum.test(i))
            {
                return false;
            }
           
        }
        return true;
    }
};