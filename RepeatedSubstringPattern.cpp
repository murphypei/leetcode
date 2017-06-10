/**
 * 判断一个字符串是不是可以有一个子串重复组成
 * 思路：寻找可能存在的子串因子，遍历（表现还不错）
 */


class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int len = s.size();
        for(int i = len / 2; i > 0; --i)
        {
            if(len % i == 0)
            {
                // 判断字符串是否可以由s.substr(0, i)这个子串组成
                int num = len / i;
                string subs = s.substr(0, i);
                int k = 1;
                for(; k < num; ++k)
                {
                    string tmp = s.substr(k * i, i);
                    if(subs != tmp)
                    {
                        break;
                    }
                    else if(k == num - 1)
                    {
                        return true;
                    }
                }
            }
        }
        return false;
        
    }
};
