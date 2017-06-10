/**
 * 给定一个数，判断是不是Perfer Number
 * 定义Perfect Number：所有因子的和（包括1，不包括本身）等于自身
 * 求所有的因子的时候一定要注意：不能循环到自身，利用开方来减少时间复杂度
 */

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
        {
            return false;
        }
        unordered_set<int> divisors = divisorsExceptItself(num);
        for(auto i : divisors)
            cout << i << endl;
        int tmp = std::accumulate(divisors.cbegin(), divisors.cend(), 0);
        return tmp == num;
    }
    
    // 求所有的因子
    unordered_set<int> divisorsExceptItself(int num)
    {
        assert(num >= 2);
        unordered_set<int> ans;
        ans.insert(1);
        for(int i = 2; i < sqrt(num) + 1; ++i)
        {
            if(num % i == 0)
            {
                ans.insert(i);
                ans.insert(num / i);
            }
        }
        return ans;
        
    }
};
