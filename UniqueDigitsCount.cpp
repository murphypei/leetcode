// Given a non-negative integer n, count all numbers with unique digits, x, where 0 ≤ x < 10n.

// Example:
// Given n = 2, return 91. 
// (The answer should be the total numbers in the range of 0 ≤ x < 100, excluding [11,22,33,44,55,66,77,88,99])
// 
// 最快的解决方法应该是排列组合方法
// 还可以用回溯的方法
// 
// 
// 排列组合
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0)
            return 1;
        int num = 0;
        for(int i = 0; i < n; ++i) {
            num = num + count(i+1);
        }
        
        return num;
    
    }
    
    // 计算k位数(10^(k-1) ~ (10^k) - 1)中UniqueDigits的个数
    int count(int k) {
        int num = 1;
        if(k < 1)
            return 0;
        else if(k == 1)
            return 10;      // 0 ~ 9    
        else {
            num *= 9;       // 第一位1~9
            for(int i = 0; i <= k - 2; ++i) {
                num = num * (9 - i);  // 从第二位开始，比如第二位0~9，但需要排除掉和第一位相同的数字
            }
        }
        
        return num;
    }
};