#include "utils.h"
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> results;
        if (nums.empty())
        {
            return results;
        }
        std::sort(nums.begin(), nums.end());
        std::vector<int> out;
        backtrack(out, nums, 0, results);
        return results;
    }

    void backtrack(vector<int> &out, const vector<int> &nums, int k, vector<vector<int>> &results)
    {
        results.push_back(out);
        if (out.size() == nums.size())
        {
            return;
        }
        for (int i = k; i < nums.size(); ++i)
        {
            if (!(i > k && nums[i] == nums[i - 1]))
            {
                out.push_back(nums[i]);
                backtrack(out, nums, i + 1, results);
                out.pop_back();
            }
        }
    }
};

int main()
{
    Solution s;
    vector<int> nums{1, 2, 2};
    auto res = s.subsetsWithDup(nums);
    printMat(res);
    std::cout << "hello world" << std::endl;
    return 0;
}