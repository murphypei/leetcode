// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// 其实就是在某个数组里面找一个序列， 序列里面的每一个元素都不能相邻，然后求其最大和


/**
 * 思路：还是动态规划, robber对待第i家有两种可能, take or not take
 * 如果要take, 为了不引发警报, 则第i-1家必须是nonTake, 此时的收益就是i-1是nonTake时的收益加上第i家的收益
 * 如果选择nonTake, 则第i-1家可以是任意的, 此时的收益就是第i-1家的收益
 * 需要三个元素记录收益
 */

class Solution {
public:
    int rob(vector<int>& nums) {
        int maxProfit = 0;
        int take = 0;
        int nonTake = 0;
        
        // 三个变量的迭代技巧性很高
        for(size_t i = 0; i < nums.size(); ++i) {
            take = nonTake + nums[i];       // i如果take, i-1一定是nonTake
            nonTake = maxProfit;            // i如果是nonTake, i-1可以是任意的
            maxProfit = max(take, nonTake); // 确定i的收益
            cout << maxProfit << endl;
        }
        return maxProfit;
    }
    
    int max(int a, int b) {
        return a > b ? a : b;
    }
};