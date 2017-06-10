/**
 * 寻找一个数组中，两个数之间满足差值为k的组合
 */

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;
        std::sort(nums.begin(), nums.end());
        // 因为有可能k为0, 数组中的数也有可能重复, 所以需要借助map来做一下处理
        unordered_map<int, int> mp;
        for(int i = 0; i < nums.size() - 1; ++i)
        {
            for(int j = i + 1; j < nums.size(); ++j)
            {
                if(nums[j] - nums[i] == k)
                    mp[nums[i]] = nums[j];
                else if(nums[j] - nums[i] > k)
                    break;
            }
        }
        return mp.size();
    }
};
