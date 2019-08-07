#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ret(2, -1);
        if (nums.empty())
        {
            return ret;
        }
        int i = 0, j = nums.size() - 1, mid;
        // search left boundary
        while (i < j)
        {
            mid = (i + j) / 2;
            if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid;
            }
        }
        if (nums[i] != target)
        {
            return ret;
        }
        else
        {
            ret[0] = i;
        }

        // search right boundary
        j = nums.size() - 1;
        while (i < j)
        {
            mid = (i + j) / 2 + 1;
            if (nums[mid] > target)
            {
                j = mid - 1;
            }
            else
            {
                i = mid;
            }
        }
        ret[1] = j;
        return ret;
    }
};