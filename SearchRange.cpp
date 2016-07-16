// Given a sorted array of integers, find the starting and ending position of a given target value.

// Your algorithm's runtime complexity must be in the order of O(log n).

// If the target is not found in the array, return [-1, -1].

// For example,
// Given [5, 7, 7, 8, 8, 10] and target value 8,
// return [3, 4].
// 

#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;


// 寻找到target, 然后再向此元素的左边和右边搜索, 确定边界
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2, -1);
        vector<int>::const_iterator begin = nums.begin();
        vector<int>::const_iterator end = nums.end() - 1;
        
        while(begin <= end) {	
        	vector<int>::const_iterator iter = begin + (end - begin) / 2;
        	
        	cout << "before****" 
        		 << "begin: " << begin - nums.begin()
    			 << " \t" 
    			 << "end: " << end - nums.begin()
    			 << endl;
    		cout << iter-nums.begin() << endl;
        	
        	if(*iter == target) {
        		cout << "iter: " << iter - nums.begin() << endl;
        		vector<int>::const_iterator left = iter;
        		while(*(left - 1) == * left && left > nums.begin()) {
        			--left;
        		}
        		result[0] = (left - nums.begin());
        		vector<int>::const_iterator right = iter;
        		while(*(right + 1) == * right && right != nums.end() - 1) {
        			++right;
        		}
        		result[1] = (right - nums.begin());
        		break;
        	}
    		else if(*iter > target) {
    			end = iter - 1;
    		}
    		else {
    			begin = iter + 1;
    		}

    		cout << "after----" 
    			 << "begin: " << begin - nums.begin()
    			 << " \t" 
    			 << "end: " << end - nums.begin()
    			 << endl;
        }
        return result;

    }
};


// 需要注意的是, find实现不需要序列是sorted的, 因为find算法从前往后寻找, 所以效率也较低
class GenericSolution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;
        // using generic algorithm: find()
        vector<int>::iterator iter = find(nums.begin(), nums.end(), target);
        result.push_back(iter - nums.begin());
        while(*iter == target && iter != nums.end()) {
            ++iter;
        }
        result.push_back(iter - nums.begin() - 1);
        return result;
    }
};


// 二分法确定左右边界
// 当找到一个target后, 需要继续搜索边界
class BinarySolution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> result(2, -1);
        int begin = 0;
        int end = nums.size() - 1;
		
		result[0] = binarySearch(nums, begin, end, target, true);
		result[1] = binarySearch(nums, begin, end, target, false);   
		return result;


    }

    // 在二分查找算法中添加一个左寻找标志, 用来区分搜索的方向
    int binarySearch(vector<int> &nums, int begin, int end, int target, bool findLeft) {
    	
    	if(begin > end)
    		return -1;
    		
		int mid = (begin + end) / 2;
		// 当找到target后, 需要根据findLeft来确定下一步搜寻的方向
		if(nums[mid] == target) {		
			int pos = findLeft ? 
					  binarySearch(nums, begin, mid - 1, target, findLeft) : 
					  binarySearch(nums, mid + 1, end, target, findLeft);
			// 如果继续搜索的找不到target, 则返回当前的结果
			return pos == -1 ? mid : pos;
		}
		else if(nums[mid] > target) {
			return binarySearch(nums, begin, mid - 1, target, findLeft);
		}
		else {
			return binarySearch(nums, mid + 1, end, target, findLeft);
		}
	}
};

int main() {
	int array[] = {2,4};
	int target = 2;
	vector<int> nums(array, array + sizeof(array) / sizeof(array[0]));
	BinarySolution s;
	vector<int> result = s.searchRange(nums, target);

	for(vector<int>::iterator iter = result.begin(); iter != result.end(); ++iter) {
		cout << *iter << "\t" << endl;
	}

}  
