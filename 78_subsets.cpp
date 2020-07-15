#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> results;
        if (!nums.empty())
        {
            vector<int> out;
            dfs(nums, out, 0, results);
        }
        return results;
    }

    void dfs(const vector<int> &nums, vector<int> out, int n, vector<vector<int>> &results)
    {
        results.emplace_back(out);
        if (out.size() == nums.size())
        {
            return;
        }
        for (int i = n; i < nums.size(); ++i)
        {
            out.push_back(nums[i]);
            dfs(nums, out, i + 1, results);
            out.pop_back();
        }
    }
};