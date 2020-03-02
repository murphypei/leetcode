#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.empty())
        {
            return true;
        }
        // 从后向前跳
        return jumpTo(nums, nums.size() - 1);
    }

    bool jumpTo(vector<int> &nums, int target_index)
    {
        // 如果从开始位置能达到当前位置，则说明可以（因为是从后向前回溯的）
        if (nums[0] >= target_index)
        {
            return true;
        }
        // 对当前位置，寻找每一个可能的起点。i 表示（到达当前位置的）起点位置
        for (int i = target_index - 1; i >= 0; --i)
        {
            // nums[i] >= target_index-i 表示从 i 能够达到 target_index
            if (nums[i] >= target_index - i)
            {
                return jumpTo(nums, i);
            }
        }
        return false;
    }
};