#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int> &A)
    {
        if (A.empty())
        {
            return 0;
        }
        // 将数组排序后，保证每个数字最低要比前面的数字大 1。
        std::sort(A.begin(), A.end());
        int res = 0, diff;
        for (int i = 1; i < A.size(); ++i)
        {
            // diff 表示要使 A[i] 最少比 A[i-1] 大 1 的操作次数。（如果 A[i] 已经 比 A[i-1] 大了，则不需要操作。
            diff = A[i - 1] - A[i] + 1;
            res += std::max(diff, 0);
            A[i] += std::max(diff, 0);
        }
        return res;
    }
};