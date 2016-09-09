// Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

// Note:
// You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.


/**
 * 关键是如果nums1的大小不是n+m的情况

 * 从后向前存储可以加快速度
 */

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n -1;
        int m_idx = m - 1;
        int n_idx = n - 1;
        while(m_idx >= 0 && n_idx >= 0) {
            if(nums2[n_idx] > nums1[m_idx])
                nums1[index--] = nums2[n_idx--];
            else
                nums1[index--] = nums1[m_idx--];
        }
        
        if(m_idx < 0) {
            while(index >= 0) 
                nums1[index--] = nums2[n_idx--];
        }
    }
};
