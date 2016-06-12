// Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

// Note:
// Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
// The solution set must not contain duplicate triplets.
//     For example, given array S = {-1 0 1 2 -1 -4},

//     A solution set is:
//     (-1, 0, 1)
//     (-1, -1, 2)


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
			quickSort(nums.begin(), nums.end());

            for(size_t i = 0; i < nums.size() - 2; ++i)
            {
				if(i > 0 && nums[i] == nums[i-1])
					continue;
                int begin = i + 1;
                int end = nums.size() - 1;
                find(begin, end, nums, nums[i]);
            }
        }
        return result;
    }
    
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