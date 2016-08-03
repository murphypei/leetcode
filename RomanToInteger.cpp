// Given a roman numeral, convert it to an integer.

// Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;

        // 判断数字是加还是减
        for(string::size_type i = 0; i < s.size(); ++i) {
            int tmp = romanNumeral(s[i]);
            if(i + 1 < s.size() && romanNumeral(s[i]) < romanNumeral(s[i+1]))
                result -= romanNumeral(s[i]);
            else
                result += romanNumeral(s[i]);
        }
        return result;
    }
    
    // 罗马数字置换函数
    int romanNumeral(char c) {
        switch (c) {
        case 'M':
            return 1000;
        case 'D':
            return 500;
        case 'C':
            return 100;
        case 'L':
            return 50;
        case 'X':
            return 10;
        case 'V':
            return 5;
        case 'I':
            return 1;
        default:
            return 0;
        }
    }
};