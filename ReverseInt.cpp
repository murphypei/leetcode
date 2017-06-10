/**
 * 给定一个整数，像反转字符串一样反转整数的各个位数字，输出结果。如果输入整数超过2的32次方，输出为0
 */

// 利用字符串
// class Solution {
// public:
//     int reverse(int x) {
//         string res = to_string(abs(x));
//         std::reverse(res.begin(), res.end());
//         long long resInt = stoll(res);
//         int tmp = (resInt<INT_MIN || resInt>INT_MAX) ? 0 : resInt;
//         return x > 0 ?  tmp : -tmp;
//     }
// };

// 利用求各个位数字（较快）
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x) {
            res = res*10 + x%10;
            x /= 10;
        }
        return (res<INT_MIN || res>INT_MAX) ? 0 : res;
    }
};