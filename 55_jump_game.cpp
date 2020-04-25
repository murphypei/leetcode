#include <vector>

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return true;
        }
        // record the longest length that can be arrived.
        int longest = 0;
        for (int i = 0; i < nums.size() - 1; ++i)
        {
            // ensurance current position can arrive.
            if (longest < i)
            {
                return false;
            }
            // update longest record
            longest = std::max(longest, nums[i] + i);
            // arrive at end
            if (longest >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};