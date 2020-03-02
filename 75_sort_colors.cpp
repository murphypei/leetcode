#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        // 只有三个数，使用两个指针，一个从左开始指向不为 0 的数，一个从右开始，指向不为 2
        // 的数，然后两个指针往中间走，遇到 0 和 2 交换。
        int red = 0, blue = (int)nums.size() - 1;
        for (int i = 0; i <= blue; ++i)
        {
            if (nums[i] == 0)
            {
                swap(nums[i], nums[red++]);
            }
            else if (nums[i] == 2)
            {
                swap(nums[i--], nums[blue--]);
            }
        }
    }
};