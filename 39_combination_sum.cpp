#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        std::vector<int> combination;
        combinationSum(candidates, target, 0, combination);
        return results;
    }

private:
    void combinationSum(vector<int> &candidates, int target, int begin, vector<int> &combination)
    {
        if (target == 0)
        {
            results.push_back(combination);
            return;
        }
        for (int i = begin; i != candidates.size() && candidates[i] <= target; ++i)
        {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], i, combination);
            combination.pop_back(); // backtrace
        }
    }

private:
    vector<vector<int>> results;
};