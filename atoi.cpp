#include <algorithm>
#include <cmath>
#include <limits>
#include <string>

using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {

        long result = 0;
        bool number_start = false;
        bool negative_sign = false;
        for (int i = 0; i < str.size(); ++i)
        {
            if (!number_start)
            {
                if (str[i] == '-' || str[i] == '+')
                {
                    negative_sign = (str[i] == '-' ? true : false);
                    number_start = true;
                }
                else if (str[i] >= '0' && str[i] <= '9')
                {
                    result = result * 10 + str[i] - '0';
                    number_start = true;
                }
                else if (str[i] == ' ')
                {
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                if (str[i] >= '0' && str[i] <= '9')
                {
                    result = result * 10 + str[i] - '0';
                    if (result > std::pow(2, 32))
                    {
                        break;
                    }
                }
                else
                {
                    break;
                }
            }
        }
        // std::cout << result << std::endl;
        result = negative_sign ? -result : result;
        if (result < std::numeric_limits<int>::min())
        {
            return std::numeric_limits<int>::min();
        }
        else if (result > std::numeric_limits<int>::max())
        {
            return std::numeric_limits<int>::max();
        }
        else
        {
            return result;
        }
    }
};