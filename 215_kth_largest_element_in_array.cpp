#include <vector>

using namespace std;

class Solution
{
public:
    // 构建最大堆来求解。
    int findKthLargest(vector<int> &nums, int k)
    {
        int sz = nums.size();

        // 构建初始最大堆，从下（除了叶子节点）向上构建。对于一个完全二叉树，其有一半的节点是叶子节点，因此非叶子节点为前
        // sz/2。
        for (int i = sz / 2 - 1; i >= 0; --i)
        {
            // 对于初始最大堆，需要保证每个节点的子节点小于父节点，因此长度为 sz。
            adjustHeap(nums, i, sz);
        }

        // 找出前 k 大。
        for (int i = sz - 1; i >= sz - k; --i)
        {
            // 把顶点（当前最大值）和当前未排序的最后一个节点交换。
            swap(nums[i], nums[0]);
            // 这里因为把最大值都换到末尾了，因此传入的序列长度变小了。
            adjustHeap(nums, 0, i);
        }
        return nums[sz - k];
    }

    void adjustHeap(vector<int> &nums, int parent, int len)
    {
        // 将当前节点与顶点（最大值）交换，然后调整位置。
        int child = 2 * parent + 1;
        // 当前父节点
        int temp = nums[parent];
        while (child < len)
        {
            // 找到较大的孩子节点
            if (child + 1 < len && nums[child] < nums[child + 1])
            {
                child++;
            }
            if (temp < nums[child])
            {
                // 这里只给父节点更新，交换的子节点不需要更新，因为这个子节点还会继续向下比较，最后才会把最开始的父节点赋值给某个子节点
                nums[parent] = nums[child];
                parent = child;
                child = 2 * parent + 1;
            }
            else
            {
                break;
            }
        }
        nums[parent] = temp;
    }
};