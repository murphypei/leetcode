#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

class Solution
{
public:
    // more common for kth element
    int findKthSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        // nums1 的长度必须小于 nums2 的长度
        if (nums1.size() > nums2.size())
        {
            return findKthSortedArrays(nums2, nums1, k);
        }

        // left 和 right 是在 nums1 中寻找分界点的左右边界。

        // 如果 k > nums2.size()，因为 nums1 的长度小于 nums2，即使 nums1 的所有元素都比 nums2 小，nums 的前
        // k-nums2.size() 个元素也要分到左半边，因此 left 从这地方开始。
        int left = std::max(0, static_cast<int>(k - nums2.size()));

        // right 类似，如果 k < nums1.size()，我们要寻找的分界点则不可能超过 k，因为即使 nums1
        // 中的所有元素都是比较小的，也只需要取前 k 个，确保 mid < k。注意 k 表示的意思。
        int right = std::min(static_cast<int>(nums1.size()), k);

        // 因为划分的长度固定为 k，因此 num1 的划分点确定了，nums2 的划分点也随之确定，用二分法找到 num1 的划分点。
        while (left < right)
        {
            int mid = left + (right - left) / 2; // num1 的划分点为 mid，左半边长度为 mid-1, num2 的左半边为 k-mid-1.
            if (nums2[k - mid - 1] > nums1[mid]) // 交叉边界比较
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        // 两个数组中各有一个分界点，需要返回较大的那个。
        int bound1 = left == 0 ? std::numeric_limits<int>::min() : nums1[left - 1];
        int bound2 = left == k ? std::numeric_limits<int>::min() : nums2[k - left - 1];
        return std::max(bound1, bound2);
    }

    double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        int len = nums1.size() + nums2.size();
        if (len % 2)
        {
            return findKthSortedArrays(nums1, nums2, len / 2 + 1);
        }
        else
        {
            return static_cast<double>(findKthSortedArrays(nums1, nums2, len / 2) +
                                       findKthSortedArrays(nums1, nums2, len / 2 + 1)) /
                   2;
        }
    }
};
