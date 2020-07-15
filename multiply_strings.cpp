#include <string>

class Solution
{
public:
    std::string multiply(std::string num1, std::string num2)
    {
        int l1 = num1.size();
        int l2 = num2.size();
        int carry, m1, m2, mul;
        std::string result(l1 + l2 + 1, '0');
        int result_idx;
        std::string temp(l2 + 1, '0');
        for (int i = l1 - 1; i >= 0; --i)
        {
            // multiply num1[i] and num2, max length of result is l2+1
            temp.resize(l2 + 1, '0');
            carry = 0;
            m1 = num1[i] - '0';
            for (int j = l2 - 1; j >= 0; --j)
            {
                m2 = num2[j] - '0';
                mul = m1 * m2 + carry;
                carry = mul / 10;
                mul = mul % 10;
                temp[j + 1] = mul + '0';
            }
            temp[0] = carry + '0';
            addTempToResult(result, temp, result.size() - (l1 - i));
        }
        for (int i = 0; i < result.size(); ++i)
        {
            if (result[i] != '0')
            {
                return result.substr(i, result.size() - i);
            }
        }
        return "0";
    }

    void addTempToResult(std::string &result, const std::string &temp, int result_tail)
    {
        int carry = 0;
        for (int i = temp.size() - 1; i >= 0; --i)
        {
            int sum = (temp[i] - '0') + (result[result_tail] - '0') + carry;
            carry = sum >= 10 ? 1 : 0;
            sum = sum % 10;
            result[result_tail] = '0' + sum;
            result_tail--;
        }
        result[result_tail] = carry + '0';
    }
};