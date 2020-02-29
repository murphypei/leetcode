#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void nextPermutation(vector<int> &nums)
    {
        int sz = nums.size();
        int i = sz - 1;
        for (i = sz - 1; i > 0; i--)
        {
            // 从后向前，第一个逆序
            if (nums[i] > nums[i - 1])
            {
                for (int j = sz - 1; j >= i; j--)
                {
                    // 第一个大于逆序的数字
                    if (nums[j] > nums[i - 1])
                    {
                        swap(nums[i - 1], nums[j]);
                        std::reverse(nums.begin() + i, nums.end());
                        break;
                    }
                }
                break;
            }
        }
        if (i == 0)
        {
            std::reverse(nums.begin(), nums.end());
        }
    }
};