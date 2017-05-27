/**
 * 在一个序列中，寻找连续子序列和最大的子序列
 *
 * 动态规划的思想：保存两个变量，一个局部最优解，一个全局最优解。
 * 在第i步，局部最优解必须包含当前元素nums[i]
 */

#include <vector>
#include <memory>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int globalMax = nums[0];
        int localMax = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            // 动态规划的递推公式
            localMax = std::max(localMax + nums[i], nums[i]);
            globalMax = std::max(globalMax, localMax);
        }

        return globalMax;
    }
};

int main(int args, char *argv[])
{
    shared_ptr<Solution> sptr = make_shared<Solution>();
    vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << sptr->maxSubArray(vec) << endl;

    getchar();
    return 0;
}
