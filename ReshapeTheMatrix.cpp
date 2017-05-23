/**
 * 实现Python或者Matlab中，形似reshape的函数功能，能够将矩阵reshape，如果输入参数有误，则返回原矩阵
 * 
 * 思路：检测一下行列的数值是否匹配，然后就一次读入原矩阵放置到新的矩阵中。
 */

#include <vector>
#include <iostream>
#include <memory>

using namespace std;

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        int orows = nums.size();
        int cols = (orows == 0 ? 0 : nums[0].size());
        if (r * c != orows *cols)
        {
            return nums;
        }

        vector<int> tmp(c);
        vector<vector<int>> res(r, tmp);
        int oi = 0, oj = 0;
        for (int i = 0; i < r; ++i)
        {
            for (int j = 0; j < c; ++j)
            {
                res[i][j] = nums[oi][oj];
                oj++;
                if (oj >= cols)
                {
                    oi++;
                    if (oi < orows)
                    {
                        oj = 0;
                    }
                }
            }
        }

        return res;
    }

    void printMatrix(vector<vector<int>> &m)
    {
        for (auto &i : m)
        {
            for (auto &j : i)
            {
                cout << j << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    vector<int> v1{1, 2};
    vector<int> v2{3, 4};
    vector<vector<int>> nums{v1, v2};
    shared_ptr<Solution> sptr = make_shared<Solution>();
    vector<vector<int>> res = sptr->matrixReshape(nums, 1, 4);
    sptr->printMatrix(res);

    getchar();
    return 0;
}