/**
 *
 */

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Solution
{
public:
    vector<int> findDuplicates(vector<int>& nums)
    {
        int len = nums.size();
        vector<int> res;
        for(int i = 0; i < len; ++i)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx] < 0)       // 如果小于0，说明已经统计过一次了
                res.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        return res;
    }
};

int main()
{
    vector<int> nums{5,4,6,7,9,3,10,9,5,6};
    shared_ptr<Solution> sptr = make_shared<Solution>();

    vector<int> res = sptr->findDuplicates(nums);

    for(auto &i : res)
        cout << i << "  ";
    cout << endl;

    getchar();
    return 0;
}