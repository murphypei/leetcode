/**
 * 数组分割: 将给定数据分割成两两一对，然后取出每一对的最小值，目的是求这种取法得到的所有最小值之和的最大值
 * 
 * 思路：因为每一对中只取出最小值，最大值必然被摒弃，所以要想最终的和最大，每一组的两个数字越接近越好
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

class Solution 
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        int res = 0;
        std::sort(nums.begin(), nums.end());
        for(auto it = nums.cbegin(); it != nums.cend(); ++it)
        {
            res += *it;
            it++;   // 相当于一次循环++两次
        }
        return res;
    }
};


int main() 
{
    vector<int> nums{1,3,2,4};
    shared_ptr<Solution> sptr = make_shared<Solution>(); 
    cout << sptr->arrayPairSum(nums) << endl;

    getchar();
    return 0;

}