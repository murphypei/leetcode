class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> temp;
        int m = 0, n = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto other = temp.find(target - nums[i]);
            if (other != temp.end())
            {
                m = i;
                n = other->second;
                break;
            }
            else
            {
                temp.insert(std::pair<int, int>(nums[i], i));
            }
        }
        return vector<int>{m, n};
    }
};