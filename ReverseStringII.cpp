/**
 * 同样是翻转字符串，但是这里是每隔k隔字符，翻转k个字符，最后如果不够k个了的话，剩几个就翻转几个。
 * 比较直接的方法就是先用n／k算出来原字符串s能分成几个长度为k的字符串，然后开始遍历这些字符串，遇到2的倍数就翻转，翻转的时候注意考虑下是否已经到s末尾了
 */

class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size(), cnt = n / k;
        for (int i = 0; i <= cnt; ++i) {
            if (i % 2 == 0) {
                if (i * k + k < n) {
                    reverse(s.begin() + i * k, s.begin() + i * k + k);
                } else {
                    reverse(s.begin() + i * k, s.end());
                }
            }
        }
        return s;
    }
};