#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> sortArray(vector<int> &nums)
    {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }

    void quickSort(vector<int> &nums, int lo, int hi)
    {
        if (lo < hi)
        {
            int j = partition(nums, lo, hi);
            quickSort(nums, lo, j - 1);
            quickSort(nums, j + 1, hi);
        }
    }

    int partition(vector<int> &nums, int lo, int hi)
    {
        // 这里标兵可以用随机选择的方式。
        int v = nums[lo];
        int i = lo, j = hi + 1;
        while (1)
        {
            while (++i <= hi && nums[i] <= v)
                ;
            // j 需要大于 lo，否则会有边界死循环。
            while (--j > lo && nums[j] >= v)
                ;
            if (i >= j)
            {
                break;
            }
            swap(nums[i], nums[j]);
        }
        swap(nums[lo], nums[j]);
        // 返回标兵的位置。
        return j;
    }
};

int main()
{
    vector<int> nums{5, 1, 1, 2, 0, 0};
    Solution s;
    auto r = s.sortArray(nums);
    for (auto i : r)
    {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}