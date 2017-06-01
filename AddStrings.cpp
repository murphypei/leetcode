/**
 * 将两个用字符串表示的数字进行相加，输出表示结果的字符串
 */

class Solution {
public:
    string addStrings(string num1, string num2) {
        string result(num1.size() + num2.size() + 1, '0');
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int k = result.size() - 1;
        int cnt = 0;
        while(i >= 0 && j >= 0)
        {
            int sum = cnt + (num1[i--] - '0') + (num2[j--] - '0');
            if (sum >= 10)
                cnt = 1;
            else
                cnt = 0;
            result[k--] = sum % 10 + '0';
        }
        while(i >= 0)
        {
           int sum = num1[i--] - '0' + cnt; 
           if (sum >= 10)
                cnt = 1;
            else
                cnt = 0;
            result[k--] = sum % 10 + '0';
        }
        while(j >= 0)
        {
           int sum = num2[j--] - '0' + cnt; 
           if (sum >= 10)
                cnt = 1;
            else
                cnt = 0;
            result[k--] = sum % 10 + '0';
        }
        result[k] = cnt + '0';
        
        auto it = result.begin();
        while(it != (--result.end()))
        {
            if(*it == '0')
                it++;
            else
                break;
        }
        result.erase(result.begin(), it);

        //cout << result;
        return result;
    }
};