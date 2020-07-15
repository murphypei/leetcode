#include <string>

using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        size_t as = a.size();
        size_t bs = b.size();
        string res(std::max(as, bs) + 1, '0');
        int carry = 0, sum = 0;
        size_t res_idx = res.size() - 1;
        while (as > 0 && bs > 0)
        {
            sum = a[as-- - 1] - '0' + b[bs-- - 1] - '0' + carry;
            if (sum > 1)
            {
                sum -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }

            res[res_idx--] = sum + '0';
        }
        while (as > 0)
        {
            sum = a[as-- - 1] - '0' + carry;
            if (sum > 1)
            {
                sum -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res[res_idx--] = sum + '0';
        }
        while (bs > 0)
        {
            sum = b[bs-- - 1] - '0' + carry;
            if (sum > 1)
            {
                sum -= 2;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            res[res_idx--] = sum + '0';
        }
        res[res_idx] = carry + '0';
        if (res.find('1') == string::npos)
        {
            return "0";
        }
        return res.substr(res.find('1'));
    }
};