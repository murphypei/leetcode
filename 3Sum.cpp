/**
 * 给定一个数组，寻找数组中三个数之和为0的元素组
 * 
 * 思路：先将数组排序，然后遍历取出一个数，再在这个数的后面的子数组中寻找两个数（双指针从两头开始遍历）
 */ 

#include <vector>
#include <algorithm>
#include <memory>
#include <iostream>
#include <iterator>

using namespace std;

class Solution {
public:
	vector< vector<int> > result;
	vector<int> target;
    
	vector<vector<int> > threeSum(vector<int>& nums) {

        if(nums.empty() || nums.size() < 3)
        {
            return result;
        }
        else
        {
			// 对原数组排序
			std::sort(nums.begin(), nums.end());
			
			// 遍历排序后的数组，取出一个元素
            for(size_t i = 0; i < nums.size() - 2; ++i)
            {
				// 在后面的子数组中查找
				if(i > 0 && nums[i] == nums[i-1])
					continue;
                int begin = i + 1;
                int end = nums.size() - 1;
                find(begin, end, nums, nums[i]);
            }
        }
        return result;
    }
	
	// 在子数组中查找
    void find(int begin, int end, vector<int>& nums, int tar)
    {
		int low = begin, high = end;
		while(low < high)
		{
			int tmp = nums[low] + nums[high] + tar;
			if( tmp == 0)
			{
				 target.clear(); 
				 target.push_back(tar);
                 target.push_back(nums[low]);
                 target.push_back(nums[high]);
                 result.push_back(target);
				 while(low < high && nums[low] == nums[low + 1])
					 low++;
				 while(low < high && nums[high] == nums[high - 1])
					 high--;
				 low++;
				 high--;
			}
			else if(tmp > 0)
			{
				high--;
			}
			else
			{
				low++;
			}
		}
	}


    void quickSort(vector<int>::iterator begin, vector<int>::iterator end)
	{
		int n = end - begin;
		if(n  <= 1)
			return;
		vector<int>::iterator low = begin, high = end;
    
		int key = *low;

		while(low < high)
		{
			while(--high > low)
			{
				if(*high < key)
				{
					swap(*high, *low);
					key = *high;
					break;
				}
			}
			while(++low < high)
			{
				if(*low > key)
				{
					swap(*high, *low);
					key = *low;
					break;
				}
			}
		}
		quickSort(begin, low);
		quickSort(low, end);
        
	}
    
    void swap(int &a, int &b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};


int main() 
{
	vector<int> nums = {-3,-2,-1,0,-1,-2,1,2,3,4,5,6};
	shared_ptr<Solution> sptr = make_shared<Solution>();
	vector<vector<int>> result = sptr->threeSum(nums);
	for(auto &vec : result) 
	{
		std::copy(vec.cbegin(), vec.cend(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}

	getchar();
	return 0;
}