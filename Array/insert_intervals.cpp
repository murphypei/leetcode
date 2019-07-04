#include <vector>

using namespace std;

bool collection_sort(const vector<int> &a, const vector<int> &b)
{
    return a[0] < b[0];
}

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> results;
        intervals.push_back(newInterval);
        if (intervals.empty())
        {
            return results;
        }
        std::sort(intervals.begin(), intervals.end(), collection_sort);
        vector<int> tmp(2);
        for (int i = 0; i < intervals.size(); ++i)
        {
            if (i == 0)
            {
                tmp = intervals[i];
                continue;
            }
            if (intervals[i][0] <= tmp[1])
            {
                tmp[1] = intervals[i][1] > tmp[1] ? intervals[i][1] : tmp[1];
            }
            else
            {
                results.push_back(tmp);
                tmp = intervals[i];
            }
        }
        results.push_back(tmp);
        return results;
    }
};