#include <vector>
#include <iostream>
#include <limits>
#include <algorithm>


class Solution {
public:
    int findKthSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2, int k)
    {
        if (nums1.size() > nums2.size())
        {
            return findKthSortedArrays(nums2, nums1, k);
        }
        int left = std::max(0, static_cast<int>(k - nums2.size()));
        int right = std::min(static_cast<int>(nums1.size()), k);
        // 因为划分的长度固定为 k，因此 num1 的划分点确定了，nums2 的划分点也随之确定，用二分法找到 num1 的划分点。
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            if (nums2[k - mid - 1] > nums1[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }

        int bound1 = left == 0 ? std::numeric_limits<int>::min() : nums1[left - 1];
        int bound2 = left == k ? std::numeric_limits<int>::min() : nums2[k - left - 1];
        return std::max(bound1, bound2);
    }

    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        int len = nums1.size() + nums2.size();
        if (len % 2)
        {
            return findKthSortedArrays(nums1, nums2, len / 2+1);
        }
        else
        {
            return static_cast<double>(findKthSortedArrays(nums1, nums2, len / 2) + findKthSortedArrays(nums1, nums2, len / 2 + 1)) / 2;
        }

    }
};

