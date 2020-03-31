#include <vector>

using namespace std;

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        vector<int> dp(nums.size(), 1);
        int max_len = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            int tmp_max_len = 0;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                {
                    tmp_max_len = std::max(tmp_max_len, dp[j]);
                }
            }
            dp[i] = tmp_max_len + 1;
            max_len = std::max(max_len, dp[i]);
        }
        return max_len;
    }
};

int main()
{
    Solution s;
    vector<int> nums{4, 10, 4, 3, 8, 9};
    s.lengthOfLIS(nums);
}