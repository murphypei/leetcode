/**
 * 给定一个序列，找出其中不是有序的子序列的最短长度
 * 换个思路理解就是将这个最短子序列排序之后，整个序列就是有序的了。
 *
 * 思路：将序列排序，比较排序后的序列和原序列之间的首尾差异性。
 */

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted(nums);
        sort(sorted.begin(), sorted.end());
        int n = nums.size(), i = 0, j = n - 1;
        while (i < n && nums[i] == sorted[i]) {
            i++;
        }
        while (j > i && nums[j] == sorted[j]) {
            j--;
        }
        return j + 1 - i;
    }
};
