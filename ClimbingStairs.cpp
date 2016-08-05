// You are climbing a stair case. It takes n steps to reach to the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

/**
 * 思路：动态规划, 第n层台阶最后一步有两种方法, 从第n-1层爬1步, 或者从第n-2层爬2步, 所以到第n层就是到第n-1层和第n-2层方法的和
 * 斐波那契数组
 */

class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2) 
            return n;
            
        int steps[n] = {0};     // steps[i]存储上i+1层台阶方法数
        steps[0] = 1;           // 爬1层只有一种方法
        steps[1] = 2;           // 爬2层有两种方法(1,2或者2)
        
        for(int i = 2; i < n; ++i) {
            steps[i] = steps[i-1] + steps[i-2];     // 动态规划
        }
        return steps[n-1];
    }
};

