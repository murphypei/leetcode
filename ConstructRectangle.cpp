/**
 * 设计矩形的长和宽，要求：面积满足给定值，长和宽的差异越小越好
 */

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        vector<int> res;
        int width = 0;
        for(int i = 1; i * i <= area; ++i)
        {
            if(area % i == 0)
                width = i;
        }
        res.push_back(area / width);
        res.push_back(width);

        return res;
    }
};

int main()
{
    shared_ptr<Solution> sptr = make_shared<Solution>();
    vector<int> res = sptr->constructRectangle(10);
    cout << res[0] << " " << res[1] << endl;

    getchar();return 0;
}