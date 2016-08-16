// Determine whether an integer is a palindrome. Do this without extra space.


/**
 * 判断一个数是否是回文数
 * 负数不是
 * 小于10是
 *
 * 分别计算两边的数, 判断是否相等即可
 **/

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        
        
        // calc integer's length
        int len = 1;        // 最高位的数量级
        while(x / len >= 10) {
            len *= 10;
        }    
        
        int left;
        int right;

        while(x != 0) {
            left = x / len;
            right = x % 10;
            
            if(left != right)
                return false;
                
            x = (x % len) / 10;
            len = len / 100;
            
        }
        
        return true;
    }
};