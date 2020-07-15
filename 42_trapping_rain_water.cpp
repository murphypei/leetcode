#include <algorithm>
#include <vector>

class Solution
{
public:
    // 把每个坐标都看作一个独立的容器，其能容纳的水量就是其左边最大的值和右边最大值夹在一起的部分，需要减去其自身高度。
    int trap(std::vector<int> &height)
    {
        if (height.empty())
            return 0;
        int ans = 0;
        int size = height.size();
        std::vector<int> left_max(size), right_max(size);

        // 遍历寻找左边最大值
        left_max[0] = height[0];
        for (int i = 1; i < size; i++)
        {
            left_max[i] = std::max(height[i], left_max[i - 1]);
        }

        // 遍历寻找右边最大值
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--)
        {
            right_max[i] = std::max(height[i], right_max[i + 1]);
        }

        // 计算每个单位夹在中间的大小（需要减去自身高度）
        for (int i = 1; i < size - 1; i++)
        {
            ans += std::min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }
};