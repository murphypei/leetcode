class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i, j;
        for(i = 0; i < nums.size() - 1; i++) {
            for(j = nums.size() - 1; j > i; j--) {
                if(nums[i] + nums[j] == target) {
                    return vector<int>{i,j};
                }
            }
        }
        
    }
};