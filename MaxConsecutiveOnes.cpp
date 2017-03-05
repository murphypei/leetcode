// Given a binary array, find the maximum number of consecutive 1s in this array.

// Example 1:
// Input: [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s.
//     The maximum number of consecutive 1s is 3.
// Note:

// The input array will only contain 0 and 1.
// The length of input array is a positive integer and will not exceed 10,000

// 在只包含0,1数组中，记录连续出现1最长的长度。只需遍历一次然后记录中间结果即可

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxLength = 0;
        int tempLength = 0;
        for (auto i : nums) {
            if (1 == i) {
                tempLength++;
            }   
            else {
                maxLength = maxLength > tempLength ? maxLength : tempLength;
                tempLength = 0;
            }
        }
        maxLength = maxLength > tempLength ? maxLength : tempLength;
        return maxLength;
    }
};