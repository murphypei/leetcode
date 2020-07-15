#include <string>

using namespace std;

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (s.size() <= 1 || numRows <= 1)
        {
            return s;
        }
        string result = s;
        int result_index = 0;
        // 一个zipzag的步长
        int step = 2 * numRows - 2;
        // 结果按行读字符
        for (int i = 0; i < numRows; ++i)
        {
            for (int j = i; j < s.size(); j += step)
            {
                result[result_index++] = s[j];
                // 一次zigzag中非首行和尾行的行有两个字符
                int jj = (j - i) + step - i;
                if (i != 0 && i != numRows - 1 && jj < s.size())
                {
                    result[result_index++] = s[jj];
                }
            }
        }
        return result;
    }
};