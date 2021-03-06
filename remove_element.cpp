#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.empty())
        {
            return 0;
        }
        int i = -1;
        for (int j = 0; j < nums.size(); ++j)
        {
            if (nums[j] != val)
            {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};