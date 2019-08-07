#include <limits>
#include <vector>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size(), n = nums2.size(), left = (m + n + 1) / 2, right = (m + n + 2) / 2;
        return (findKthTwoSortedArrays(nums1, 0, nums2, 0, left) + findKthTwoSortedArrays(nums1, 0, nums2, 0, right)) / 2.0;
    }
    // 在两个有序的数组中查找第 K 个数字，beg1 和 beg2 分别是两个数组查找的起始位置
    int findKthTwoSortedArrays(vector<int> &nums1, int beg1, vector<int> &nums2, int beg2, int k)
    {
        // 起始位置超过某个数组的长度，直接返回另一个数组中第 k 个数
        if (beg1 >= nums1.size())
        {
            return nums2[beg2 + k - 1];
        }
        if (beg2 >= nums2.size())
        {
            return nums1[beg1 + k - 1];
        }
        // 递归终止条件
        if (k == 1)
        {
            return std::min(nums1[beg1], nums2[beg2]);
        }
        // 分别求出两个数组（自起始位置）的第 k/2 个数，通过比较大小淘汰某个数组中 k/2 个数，需要考虑可能某个数组中元素不足
        int midVal1 = (beg1 + k / 2 - 1 < nums1.size()) ? nums1[beg1 + k / 2 - 1] : numeric_limits<int>::max();
        int midVal2 = (beg2 + k / 2 - 1 < nums2.size()) ? nums2[beg2 + k / 2 - 1] : numeric_limits<int>::max();
        if (midVal1 < midVal2)
        {
            return findKthTwoSortedArrays(nums1, beg1 + k / 2, nums2, beg2, k - k / 2);
        }
        else
        {
            return findKthTwoSortedArrays(nums1, beg1, nums2, beg2 + k / 2, k - k / 2);
        }
    }
};