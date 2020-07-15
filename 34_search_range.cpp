#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        // 二分查找的三种方式的应用。

        // 是否存在 target
        int n = binarySearchIsExist(nums, target);
        if (n == -1)
        {
            return vector<int>{-1, -1};
        }

        // target 的左边界（第一个大于等于 target 的数）
        int left = binarySearchLeft(nums, target);
        // target 的右边界
        int right = binarySearchRight(nums, target);

        return vector<int>{left, right};
    }

    int binarySearchIsExist(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1, mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (target == nums[mid])
            {
                return mid;
            }
            else if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return -1;
    }

    // 查找第一个大于等于它的数
    int binarySearchLeft(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size(), mid;
        while (left < right)
        {
            mid = (left + right) >> 1;
            // 这里 left 部分必然只包含了小于 target 的数。
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left == nums.size() ? -1 : left;
    }

    // 查找最后一个小于等于它的数
    int binarySearchRight(vector<int> &nums, int target)
    {
        int left = -1, right = nums.size() - 1, mid;
        while (left < right)
        {
            mid = (left + right + 1) >> 1;
            // 这里 left 的更新条件包含了等于的选项，因此 right 必然是大于 target 的值，所以返回的是 left。
            if (nums[mid] <= target)
            {
                left = mid;
            }
            else
            {
                right = mid - 1;
            }
        }
        return left;
    }
};