#include <vector>

using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        auto iter = nums.begin();
        int previous = *iter;
        iter++;
        int appeared = 1;
        for (; iter != nums.end();)
        {
            if (*iter != previous)
            {
                appeared = 1;
                previous = *iter;
                iter++;
            }
            else
            {
                if (appeared > 1)
                {
                    iter = nums.erase(iter);
                }
                else
                {
                    iter++;
                }
                appeared++;
            }
        }
        return nums.size();
    }
};