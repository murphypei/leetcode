#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int largestRectangleArea(vector<int> &height)
    {
        int res = 0;
        // 本质是暴力解法，优化了一些重复计算。
        for (int i = 0; i < height.size(); ++i)
        {
            // 先找到找右边界，因为如果是递增，则面积一定增加，所以这里可以避免一些重复寻找。
            if (i + 1 < height.size() && height[i] <= height[i + 1])
            {
                continue;
            }
            // 向左寻找左边界。
            int minH = height[i];
            for (int j = i; j >= 0; --j)
            {
                minH = min(minH, height[j]);
                int area = minH * (i - j + 1);
                res = max(res, area);
            }
        }
        return res;
    }
};