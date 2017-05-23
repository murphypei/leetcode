/**
 * 给定包含n个数的数组，数组元素满足1 ≤ a[i] ≤ n ，数组元素有重复，寻找1~n中未出现在数组中的元素
 * 
 * 要求：不使用额外空间，O(n)复杂度
 *
 * 思路：在原数组中做操作，因为数组中的元素也可以作为下标来用，先将循环的元素对应数组位置上的数值取负数，
 * 然后再便利数组，元素仍然为正的下标位置则是未出现的数
 */

#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Solution 
{
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res;
        int len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            int idx = abs(nums[i]) - 1;         // 因为是在原数组上修改的，所以取负数操作会影响后面的循环，必须加上abs
            nums[idx] = nums[idx] > 0 ? -nums[idx] : nums[idx];
        }

        for(int i = 0; i < len; ++i)
        {
            if(nums[i] > 0)
                res.push_back(i + 1);
        }
        
        return res;
    }
};

int main()
{
    vector<int> nums{4,3,2,7,8,2,3,1};
    shared_ptr<Solution> sptr = make_shared<Solution>();
    vector<int> res = sptr->findDisappearedNumbers(nums);
    cout << res.size() << endl;

    getchar();
    return 0;
}