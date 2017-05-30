/**
* 用于求n个数中第k小(大)的数
*
* 通过一些操作，实现在原数组中进行操作，不开辟新的内存空间
*/

#include <iostream>
#include <vector>
#include <memory>

using namespace std;

class Solution
{
public:
	// 因为只对5个数进行排序，所以用任意排序方法均可，此处用冒泡
	// start和end传入的是下标值
	void bubble(int *nums, int start, int end)
	{
		for (int i = 0; i < (end - start); ++i)
		{
			for (int j = start; j < end - i; ++j)
			{
				if (nums[j] > nums[j + 1])
				{
					std::swap(nums[j + 1], nums[j]);
				}
			}
		}
	}

	/* 找到中位数的中位数，返回其下标 */
	// left和right传入的是下标值
	int findMid(int *nums, int left, int right)
	{
		if (right - left + 1 <= 5)
		{
			bubble(nums, left, right);
			return (left + right) >> 1;      // 返回中位数
		}

		int j = left - 1;
		// 5个数一组，进行排序，然后取中位数，并将其放在左侧（这样可以实现原地排序）
		for (int i = left; i <= right; i += 5)
		{
			if (i + 4 <= right)
			{
				bubble(nums, i, i + 4); 
				// 将中位数和左边的数进行交换存储
				swap(nums[++j], nums[i + 2]);
			}	
			else
			{
				bubble(nums, i, right);
				swap(nums[++j], nums[(right - i) / 2 + i]);
			}
		}

		return findMid(nums, left, j);
	}


	/* 在原数组中进行分区，通过交换实现，pivot_index是中位数的下标*/
	int partition(int* nums, int left, int right, int pivot_index)
	{
		// 将中位数的下标放在最右边
		swap(nums[pivot_index], nums[right]);
		int j = left;
		for (int i = left; i < right; ++i)
		{
			if (nums[i] <= nums[right])
			{
				// j指向的永远都是比基准要大的第一个数的位置
				swap(nums[j++], nums[i]);
			}
		}
		swap(nums[j], nums[right]);
		return j;
	}


	// 给定一个数组，返回第k小的的元素
	void selection(int *nums, int start, int end, int k)
	{
		if (start == end)
			return;
        // 寻找中位数的中位数
		int pivot_index = findMid(nums, start, end);
        // 利用找到的中位数的下标来进行分区
		int index = partition(nums, start, end, pivot_index);
        // 判断是否符合要寻找的数
		int len = index - start + 1;
		if (len == k)
			return ;
		else if (len > k)
			selection(nums, start, index - 1, k);
		else
			selection(nums, index + 1, end, k - len);
	}
};

int main(int args, char * argv[])
{
	int array[] = { 1, 1, 2, 3, 1, 5, -1, 7, 8, -10 };
	shared_ptr<Solution> sptr = make_shared<Solution>();
	//sptr->bubble(array, 0, sizeof(array) / sizeof(array[0]) - 1);


	sptr->selection(array, 0, sizeof(array) / sizeof(array[0]) - 1, 2);
	for (auto i : array)
	{
		cout << i << " ";
	}
	cout << "\n";
	getchar();
	return 0;
}