#include <sstream>
#include <string>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if (n <= 1)
        {
            return std::string("1");
        }

        std::string tmp = countAndSay(n - 1);
        std::ostringstream oss;
        char c = tmp[0];
        int count = 1;
        for (int i = 1; i < tmp.size(); ++i)
        {
            if (tmp[i] == c)
            {
                count++;
            }
            else
            {
                oss << count << c;
                c = tmp[i];
                count = 1;
            }
        }
        oss << count << c;
        return oss.str();
    }
};