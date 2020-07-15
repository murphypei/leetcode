#include <iostream>
#include <vector>

class Solution
{
public:
    int firstMissingPositive(std::vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); ++i)
        {
            // while is very important
            while (nums[i] - 1 < i && nums[i] > 0 && nums[nums[i] - 1] != nums[i])
            {
                std::swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] - 1 != i)
            {
                return i + 1;
            }
        }
        return nums.empty() ? 1 : nums[nums.size() - 1] + 1;
    }
};