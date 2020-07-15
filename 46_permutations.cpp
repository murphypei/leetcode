#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> result;
        if (!nums.empty())
        {
            std::sort(nums.begin(), nums.end());
            next_permutation(nums, result);
        }
        return result;
    }

    // 有序字典排列求下个排列的方法：
    // 从右向左找到一个逆序（后面大于前面）的位置，记录前面的位置；
    // 再次从右寻找第一个大于记录位置的数，交换两个数，此时，记录后面的数字（从左向右）一定是递减有序的；
    // 反转记录位置后面的序列。
    void next_permutation(vector<int> &nums, vector<vector<int>> &result)
    {
        result.emplace_back(nums);
        int m = nums.size() - 2;
        for (; m >= 0; --m)
        {
            if (nums[m] < nums[m + 1])
            {
                break;
            }
        }
        if (m < 0)
        {
            return;
        }
        for (int i = nums.size() - 1; i > m; --i)
        {
            if (nums[i] > nums[m])
            {
                swap(nums[i], nums[m]);
                break;
            }
        }
        std::reverse(nums.begin() + m + 1, nums.end());
        next_permutation(nums, result);
    }
};