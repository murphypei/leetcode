#include <vector>

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int cur = 0;  // the rightmost that can be arrived currently
        int last = 0; // the rightmost that already arrived
        int ret = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > last)
            {
                last = cur;
                ++ret;
            }
            cur = std::max(cur, nums[i] + i);
        }
        return ret;
    }
};