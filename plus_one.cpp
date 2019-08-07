#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            if (digits[i] + 1 > 9)
            {
                digits[i] = digits[i] + 1 - 10;
                if (i == 0)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
            else
            {
                digits[i] += 1;
                return digits;
            }
        }
        return digits;
    }
};