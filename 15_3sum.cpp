#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> res;
        if (nums.size() >= 3)
        {
            std::sort(nums.begin(), nums.end());
            for (int i = 0; i < nums.size() - 2; ++i)
            {
                if (i > 0 && nums[i] == nums[i - 1])
                {
                    continue;
                }
                for (int j = i + 1, k = nums.size() - 1; j < k;)
                {
                    if (j > i + 1 && nums[j] == nums[j - 1])
                    {
                        j++;
                        continue;
                    }
                    if (k < nums.size() - 1 && nums[k] == nums[k + 1])
                    {
                        k--;
                        continue;
                    }

                    if (nums[j] + nums[k] + nums[i] == 0)
                    {
                        res.emplace_back(vector<int>{nums[i], nums[j], nums[k]});
                        j++;
                        k--;
                    }
                    else if (nums[j] + nums[k] + nums[i] > 0)
                    {
                        k--;
                    }
                    else
                    {
                        j++;
                    }
                }
            }
        }
        return res;
    }
};