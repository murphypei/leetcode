#include <limits>

using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        long r = 0;
        while (x)
        {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return (r < numeric_limits<int>::max() && r > numeric_limits<int>::min()) ? r : 0;
    }
};