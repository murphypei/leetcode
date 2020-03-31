#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits>
#include <string>

using namespace std;
class Solution
{
public:
    int myAtoi(string str)
    {

        long result = 0;
        int sign = 1;
        int index = 0;
        size_t len = str.size();

        // 去掉前面的空格
        while (index < len && str[index] == ' ')
        {
            index++;
        }
        if (index == len)
        {
            return 0;
        }

        // 判断第一个字符
        if (str[index] == '-')
        {
            sign = -1;
            index++;
        }
        else if (str[index] == '+')
        {
            index++;
        }
        else if (str[index] > '9' || str[index] < '0')
        {
            return 0;
        }

        // 转换数字直到符合终止条件
        while (index < len)
        {
            if (str[index] >= '0' && str[index] <= '9')
            {
                result = result * 10 + str[index++] - '0';
                // 判断 result 是否已经超过了 int 的表示范围
                if (result - 10 > std::numeric_limits<int>::max())
                {
                    break;
                }
            }
            else
            {
                break;
            }
        }
        result *= sign;

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

int main()
{
    Solution s;
    std::cout << s.myAtoi("-000000000000001") << std::endl;
    std::cout << s.myAtoi("200000000000000000000000") << std::endl;
}
