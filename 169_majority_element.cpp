#include <vector>

using namespace std;

class Solution
{
public:
    // 因为元素一定存在且超过半数，所以分区后的中间值就是所求值。
    int majorityElement(vector<int> &nums)
    {
        int target = (nums.size() - 1) / 2;
        int lo = 0, hi = nums.size() - 1;
        while (1)
        {
            int k = partition(nums, lo, hi);
            if (k == target)
            {
                return nums[k];
            }
            else if (k < target)
            {
                lo = k + 1;
            }
            else
            {
                hi = k - 1;
            }
        }
    }

    // 快排分区算法。
    int partition(vector<int> &nums, int lo, int hi)
    {
        int v = nums[lo];

        int i = lo, j = hi + 1;
        while (1)
        {
            while (++i <= hi && nums[i] < v)
                ;
            while (--j >= lo && nums[j] > v)
                ;
            if (j <= i)
            {
                break;
            }
            std::swap(nums[i], nums[j]);
        }
        std::swap(nums[lo], nums[j]);
        return j;
    }
};