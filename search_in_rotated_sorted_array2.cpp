#include <vector>

using namespace std;

class Solution
{
public:
    bool search(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return true;

            // 这里大致思路和 I 类似，但是要处理：
            // 如果中间的数等于最右边的数，因为可能存在重复，因此目标值可能在右边也可能在左边。
            // [1,2,1,1,1] 和 [1,1,1,2,1]，中间值为 1，目标值 2 可能在右边也可能在左边。

            // [mid, right] 有序
            if (nums[mid] < nums[right])
            {
                if (nums[mid] < target && nums[right] >= target)
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            // 因为 nums[left] <= nums[right]， 因此 nums[mid] > nums[left]，所以 [left,mid] 有序。
            else if (nums[mid] > nums[right])
            {
                if (nums[left] <= target && nums[mid] > target)
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            // 当 nums[mid] == nums[right]，将 right 前移一位，直到不等。
            else
                --right;
        }
        return false;
    }
};