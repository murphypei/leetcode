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

            // 思路一定要清晰：二分查找的关键是知道什么时候让 left = mid + 1，什么时候让 right = mid - 1。
            // 不管 mid 落在哪里，[left, mid] 和 [mid, right] 必然有一个是有序的。

            // 假如 [left, mid] 有序。
            if (nums[mid] >= nums[left]) // 因为没有重复元素，所以等号其实没用。
            {
                if (target >= nums[left] && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // [mid, right] 有序。
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