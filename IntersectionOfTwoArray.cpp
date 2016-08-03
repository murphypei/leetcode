// Given two arrays, write a function to compute their intersection.

// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].

// Note:
// Each element in the result must be unique.
// The result can be in any order.


// 思路：在一个数组中二分查找另一个数组的元素, 需要注意重复元素的处理

#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if(nums1.empty() || nums2.empty())
            return result;
        
        // 对较小的数组进行排序
        if(nums1.size() < nums2.size()) 
            result = myFind(nums1, nums2);
        else 
            result = myFind(nums2, nums1);
        
        return result;
    }
    
    // myFind中nums1的长度较短
    vector<int> myFind(vector<int>& nums1, vector<int>& nums2) {
        // 存放结果
        vector<int> result;
        // 排序
        sort(nums1.begin(), nums1.end());
        // 去掉重复元素
        vector<int>::iterator position = unique(nums1.begin(), nums1.end());    // 返回重复元素起始位置
        nums1.erase(position, nums1.end());
        
        for(size_t idx = 0; idx < nums2.size(); ++idx) {
            vector<int>::iterator pos = lower_bound(nums1.begin(), nums1.end(), nums2[idx]);
            if(pos != nums1.end() && *pos == nums2[idx]) {
                result.push_back(*pos);
                nums1.erase(pos);
            }
        }
        return result;
    }
    
};
