/**
 * 旋转数组
 * Rotate an array of n elements to the right by k steps.
 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 */

// class Solution {
// public:
//     void rotate(vector<int>& nums, int k) {
//         if(nums.size() <= 1 || k == 0)
//             return;
//         std::reverse(nums.begin(), nums.end());
//         std::reverse(nums.begin(), nums.begin() + k);
//         std::reverse(nums.begin() + k, nums.end());
        
//     }
// };

// 上述代码无法通过测试用例： array: [1,2,3,4,5,6]  k = 11


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (nums.empty() || (k %= nums.size()) == 0) return;
        int n = nums.size();
        reverse(nums.begin(), nums.begin() + n - k);
        reverse(nums.begin() + n - k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};
