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
        return jumpHelper(nums, nums.size() - 1);
    }

    bool jumpHelper(vector<int> &nums, int target_index)
    {
        if (nums[0] >= target_index)
        {
            return true;
        }
        for (int i = target_index - 1; i >= 0; --i)
        {
            if (nums[i] >= target_index - i)
            {
                return jumpHelper(nums, i);
            }
        }
        return false;
    }
};