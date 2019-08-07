#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(std::vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
            {
                return mid;
            }
            if (nums[mid] >= nums[left])
            {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else
            {
                if (target <= nums[right] && target >= nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};