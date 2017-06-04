/**
 * 最长有趣子序列：要求从一个序列中找到一个子序列（不要求连续），子序列中必须包含两个数，两个数相差1，求这样的最长子序列
 *
 * 思路：对原序列中的数字分布进行统计，求出连续两个数的个数最多的组合就可以。（因为不要求子序列是连续的）
 */


class Solution {
public:
    int findLHS(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        unordered_map<int, int> mp;
        int maxNum = *max_element(nums.cbegin(), nums.cend());
        int minNum = *min_element(nums.cbegin(), nums.cend());

        for(auto &i : nums) 
            mp[i]++;
        
        int res = 0;

        for(auto it = mp.cbegin(); it != mp.cend(); ++it)
        {
            int a = 0, b = 0, c = 0;
            a = it->second;
            auto minIt = mp.find(it->first - 1);
            if(minIt != mp.end())
                b = minIt->second;
            auto maxIt = mp.find(it->first + 1);
            if(maxIt != mp.end())
                c = maxIt->second;
            if(b || c)
                res = max(res, max(a+b, a+c));
        }

        return res;
    }
};