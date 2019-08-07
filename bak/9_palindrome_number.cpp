// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) {
            return false;
        }

        // 获取数字的位数
        int bit_num = 0;
        int tmp = x;
        while(tmp >= 10) {
            bit_num++;
            tmp = tmp / 10;
        }
        
        tmp = x;
        int left = 0, right = 0;
        while(bit_num > 0) {
            // 获取数字最左边位和最右边的数
            left = tmp / int(std::pow(10, bit_num));
            right = tmp % 10;
            if(left == right) {
                // 删除最左边和最右边的数
                tmp = (tmp - right * std::pow(10, bit_num)) / 10;
                bit_num -= 2;
            }
            else {
                return false;
            }
        }
        return true;
    }
};