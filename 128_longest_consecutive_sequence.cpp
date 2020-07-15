#include <unordered_set>
#include <vector>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        // add element to set only once
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestResult = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            int tmpLongest = 1;
            // find low boundary
            int lo = nums[i] - 1;
            while (numSet.find(lo) != numSet.end())
            {
                tmpLongest++;
                numSet.erase(lo);
                lo--;
            }
            // find high boundary
            int hi = nums[i] + 1;
            while (numSet.find(hi) != numSet.end())
            {
                tmpLongest++;
                numSet.erase(hi);
                hi++;
            }
            longestResult = std::max(longestResult, tmpLongest);
        }
        return longestResult;
    }
};