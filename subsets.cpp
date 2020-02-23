#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        vector<int> out;
        helper(0, nums, out, res);
        return res;
    }

    void helper(int n, const vector<int> &nums, vector<int> out, vector<vector<int>> &res)
    {
        res.push_back(out);
        if (out.size() == nums.size())
        {
            return;
        }
        for (int i = n; i < nums.size(); ++i)
        {
            out.push_back(nums[i]);
            helper(i + 1, nums, out, res);
            out.pop_back();
        }
    }
};