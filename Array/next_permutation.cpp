class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k = -1;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            if (nums[i] < nums[i+1])
            {
                k = i;
            }
        }
        if (k < 0)
        {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        
        for (int j = nums.size() - 1; j > k; --j)
        {
            if (nums[j] > nums[k])
            {
                std::swap(nums[k], nums[j]);
                break;
            }
        }
        std::reverse(nums.begin() + k + 1, nums.end());
    }
};