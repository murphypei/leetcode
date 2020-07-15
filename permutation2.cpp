#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        // using dict sort algorithm
        std::sort(nums.begin(), nums.end());
        vector<vector<int>> res{nums};
        auto temp = nums;
        while (1)
        {
            next_permutation(nums);
            if (nums == temp)
            {
                return res;
            }
            res.push_back(nums);
        }
    }

    void next_permutation(vector<int> &nums)
    {
        // find the first ascending order number
        int k = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] < nums[i + 1])
            {
                k = i;
            }
        }
        // if the nums is already a reversed order, then return the ordered permutation
        if (k < 0)
        {
            std::reverse(nums.begin(), nums.end());
        }
        else
        {
            // find the rightmost number that greater than the first ascending order number, swap them
            for (int j = nums.size() - 1; j > k; --j)
            {
                if (nums[j] > nums[k])
                {
                    std::swap(nums[k], nums[j]);
                    break;
                }
            }
            // sort numbers after the first ascending order number
            std::reverse(nums.begin() + k + 1, nums.end());
        }
    }
};