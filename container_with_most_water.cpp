#include <algorithm>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        auto front_iter = height.begin();
        auto rear_iter = height.end() - 1;
        int max_area = 0;
        while (front_iter < rear_iter)
        {
            auto min_elem = std::min(*front_iter, *rear_iter);
            auto area = min_elem * std::distance(front_iter, rear_iter);
            area = std::max(area, max_area);
            if (*rear_iter < *front_iter)
            {
                rear_iter--;
            }
            else
            {
                front_iter++;
            }
        }
        return max_area;
    }
};