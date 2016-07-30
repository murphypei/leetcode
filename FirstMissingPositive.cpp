// Given an unsorted integer array, find the first missing positive integer.

// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.

// Your algorithm should run in O(n) time and uses constant space.


/** 
 * 思路：充分利用nums[i]中大部分数是连续的性质, 一次遍历将nums[i]放置在固定的位置上, 然后再遍历一次检查固定位置上的数是否正确。
 * 注意：第一次遍历交换的条件
 */


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.empty())
            return 1;

        for(int i = 0; i < nums.size(); ++i) {
            while(nums[i] != i + 1) {       // 直到该位置安放为固定的数
                if(nums[i] > nums.size() || nums[i] <= 0 || nums[i] == nums[nums[i] - 1])       // 数组范围的限制条件
                    break;
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        for(int i = 0; i < nums.size(); ++i) {
            cout << nums[i] << "\t";
            if(nums[i] != i + 1){
                cout << endl;
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
    
    
    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
};


int main() {
	Solution s;
	int array[] = {3,4,2,1,7,8};
    vector<int> vec(array, array + 6);
    cout << endl;
    cout << s.firstMissingPositive(vec) << endl;
    getchar();
    return 0;
}
