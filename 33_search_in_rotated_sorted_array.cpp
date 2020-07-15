#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        // 思路一定要清晰：二分查找的关键是知道什么时候让 left = mid + 1，什么时候让 right = mid - 1。
        // 不管 mid 落在哪里，[left, mid] 和 [mid, right] 必然有一个是有序的，所以从这方面入手。

        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (target == nums[mid])
            {
                return mid;
            }

            // left ~ mid 递增，这里等号不能省略，确保不是这种情况的时候，mid~right是递增的。
            if (nums[mid] >= nums[left])
            {
                if (target >= nums[left] && target < nums[mid])
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }
            else // mid~right 递增
            {
                if (target > nums[mid] && target <= nums[right])
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};