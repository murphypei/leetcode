// Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.

// Example:
// Given nums = [-2, 0, 3, -5, 2, -1]

// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
// Note:
// You may assume that the array does not change.
// There are many calls to sumRange function.

class NumArray {
public:
    NumArray(vector<int> &nums) {
       _nums.clear();
       _nums.push_back(0);
       for(auto e: nums)
        _nums.push_back(_nums.back() + e);
    }

    int sumRange(int i, int j) {
        return _nums[j+1] - _nums[i];
    }
    
private:
    vector<int> _nums;
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);