/** 
 * 找到序列中第三大的数，如果不存在（比如只有两个数），则返回最大的数
 * 思路：排序之后就很好处理了
 */
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        if(nums.empty())
            return 0;
        std::sort(nums.begin(), nums.end());
        int n = nums.size();
        int currentMax = nums[n - 1];
        int cnt = 1; // 当前第几大
        for(int i = n - 2; i >= 0; --i)
        {
            if(nums[i] < currentMax) {
                cnt++;
                currentMax = nums[i];
            }
            if(cnt == 3)
                return nums[i];
        }
        
        return nums[nums.size() - 1];
    }
};
