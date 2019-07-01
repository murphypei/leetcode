#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        unsigned int closest_distance = std::numeric_limits<unsigned int>::max(), distance = 0;
        int sum = 0, closest_sum = 0;
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
                sum = nums[j] + nums[k] + nums[i];
                distance = std::abs(target - sum);
                if (distance < closest_distance)
                {
                    closest_distance = distance;
                    closest_sum = sum;
                }
                if (sum > target)
                {
                    k--;
                    continue;
                }
                else if (sum < target)
                {
                    j++;
                    continue;
                }
                else
                {
                    break;
                }
            }
        }
        return closest_sum;
    }
};