#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        auto r = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            r = r ^ nums[i];
        }
        return r;
    }
};