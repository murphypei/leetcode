/**
 * 给一个长度为偶数的整数数组，数组中不同数字都代表不同糖果，将糖果平均分给弟弟和妹妹(每个人得到的个数相同)，妹妹最多能得到几种糖果。
 * 
 * 记录糖果种类，若糖果种类大于数组的一半，妹妹最多得到candies.size()/2种糖果,否则每种糖果都可以得到
 */

#include <unordered_set>
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int>& candies)
    {
        unordered_set<int> candyClasses;
        for(auto c : candies)
        {
            candyClasses.insert(c);
        }
        return min(candyClasses.size(), candies.size() / 2);
    } 
};

int main()
{
    vector<int> nums{1,2,2,3};
    shared_ptr<Solution> sptr = make_shared<Solution>();
    cout << sptr->distributeCandies(nums) << endl;
    getchar();
    return 0;
}

