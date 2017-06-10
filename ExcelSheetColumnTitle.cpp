/**
 * 将给定正整数转换成Excel表格行号的形式
    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
 */


// 本质就是10进制转26进制
class Solution {
public:
    string convertToTitle(int n) {
        string res;
        while(n > 0)
        {
            int modNum = (n - 1) % 26;
            res.insert(res.begin(), modNum  + 'A');
            n = (n - 1) /  26;
        }
        return res;
    }
};
