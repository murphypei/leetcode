/**
 * 在有序数组中寻找两个数，相加之和等于一个target
 * 用两个指针，一个在头，一个在尾，然后根据两个指针和的结果来确定移动哪个指针，每次移动两个指针之间距离的一半
*/

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int tail = nums.size() - 1;
        int head = 0;

        while(head < tail)  // 一个元素不能使用两次
        {
            if(nums[tail] + nums[head] > target)
            {
                tail--;
            }
            else if(nums[tail] + nums[head] < target)
            {
                head++;
            }
            else
            {
                return vector<int>{head+1, tail+1};
            }
        }
    }
};

int main()
{
    vector<int> nums{2,7,11,15};
    shared_ptr<Solution> sptr = make_shared<Solution>();

    vector<int> res = sptr->twoSum(nums, 9);
    for(auto i : res)
        cout << i << " ";
    
    cout << endl;
    getchar();
    return 0;
}