#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    // 利用快排中的分区来求解
    int findKthLargest(vector<int> &nums, int k)
    {
        int lo = 0, hi = nums.size() - 1;
        // 目标下标
        int target = nums.size() - k;
        while (true)
        {
            int j = partition(nums, lo, hi);
            if (j == target)
            {
                return nums[j];
            }
            else if (j < target)
            {
                lo = j + 1;
            }
            else
            {
                hi = j - 1;
            }
        }
    }

    // 快排中的分区，返回的是标兵在分好的数组中的位置。
    int partition(vector<int> &nums, int lo, int hi)
    {
        // 选择标兵
        int v = nums[lo];

        int i = lo, j = hi + 1;
        while (1)
        {
            // 注意这里 i 和 j 的处理，一定要保证 i 和 j 在 外层 while 中更新，否则死循环。
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

        std::swap(nums[j], nums[lo]);
        return j;
    }
};

int main()
{
    vector<int> a{3, 3, 3, 3, 3, 3, 3, 3};
    int k = 2;
    Solution s;
    std::cout << s.findKthLargest(a, k) << std::endl;
    return 0;
}
