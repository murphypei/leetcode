#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        std::sort(candidates.begin(), candidates.end());
        vector<int> combinations;
        combinationSum2(candidates, target, 0, combinations);
        return results;
    }

private:
    void combinationSum2(vector<int> &candidates, int target, int begin, vector<int> &combinations)
    {
        if (target == 0)
        {
            results.push_back(combinations);
            return;
        }
        for (int i = begin; i < candidates.size() && candidates[i] <= target; ++i)
        {
            if (i == begin || candidates[i] != candidates[i - 1])
            {
                combinations.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], i + 1, combinations);
                combinations.pop_back();
            }
        }
    }

private:
    vector<vector<int>> results;
};