// Implement atoi which converts a string to an integer.

// 1. 忽略空格，直到第一个非空字符，如果第一个非空字符是非数字字符或者非负号字符，输出0
// 2. 转换数字字符直到第一个非数字字符
// 3. 负数
// 4. 超过整数（2的32次方）的范围，返回整数的最大值（正数）或者最小值

class Solution {
public:
    int myAtoi(string str) {
        
        long result = 0;
        bool number_start = false;
        bool negative_sign = false;
        for(int i = 0; i < str.size(); ++i) {
            if(!number_start) {
                if(str[i] == '-' || str[i] == '+'){
                    negative_sign = (str[i] == '-' ? true : false);
                    number_start = true;
                }
                else if(str[i] >= '0' && str[i] <= '9') {
                    result = result * 10 +  str[i] - '0';
                    number_start = true;
                } 
                else if(str[i] == ' ') {
                    continue;
                } 
                else {
                    break;
                }
            }
            else {
                if(str[i] >= '0' && str[i] <= '9') {
                    result = result * 10 + str[i] - '0';
                    if(result > std::pow(2, 32)){
                        break;
                    }
                }
                else {
                    break;
                }
            }
        }
        // std::cout << result << std::endl;
        result = negative_sign ? -result : result;
        if(result < INT_MIN) {
            return INT_MIN;
        } 
        else if (result > INT_MAX) {
            return INT_MAX;
        }
        else {
            return result;
        }
    }
};