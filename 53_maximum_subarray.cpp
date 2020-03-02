#include <limits>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        // 贪心算法
        int max = std::numeric_limits<int>::min();
        int cur = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            cur += nums[i];
            if (cur > max)
            {
                max = cur;
            }
            // 如果这一部分值小于 0，则需要重新开始搜索，因为加上这一部分就会导致后面的和变小。
            if (cur < 0)
            {
                cur = 0;
            }
        }
        return max;
    }
};