/*
 * 寻找字符串中最长回文子串
 * 中心扩展法：把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串。
 * 算法复杂度为O(N^2)。
 * 但是要考虑两种情况：
    * 1、像aba，这样长度为奇数。
    * 2、想abba，这样长度为偶数。
 */

#include <string>
#include <iostream>

using namespace std;

string FindLongestPalindromeSubStr(const string &src)
{
    string res;

    int length = src.size();
    int maxLength = 0;
    int start = 0;

    // 奇数情况
    for (int i = 0; i < length; ++i)
    {
        int pre = i - 1;
        int next = i + 1;
        while (pre >= 0 && next < length && src.at(pre) == src.at(next))
        {

            if (next - pre + 1 > maxLength)
            {
                maxLength = next - pre + 1;
                start = pre;
            }
            --pre;
            ++next;
        }
    }
    
    // 偶数情况
    for (int i = 0; i < length; ++i)
    {
        int pre = i - 1;
        int next = i;
        while (pre >= 0 && next < length && src.at(pre) == src.at(next))
        {

            if (next - pre + 1 > maxLength)
            {
                maxLength = next - pre + 1;
                start = pre;
            }
            --pre;
            ++next;
        }
    }

    if (maxLength > 1)
        return src.substr(start, maxLength);
    
    return res;
}


// 动态规划的求解方法
// 回文字符串的子串也是回文，比如P[i,j]（表示以i开始以j结束的子串）是回文字符串，那么P[i+1,j-1]也是回文字符串。
// 这样最长回文子串就能分解成一系列子问题了。
// 需要定义状态方程和转移方程，而且需要额外的空间来存储状态。
// 复杂度是N^2
string DynamicProgramming(const string &src)
{
    string res;
    const int length = src.size();
    int maxLength = 0;
    int start = 0;

    bool p[50][50] = { false };  // 暂且为50吧...可以用vector

    // 初始化单个字符和相邻字符的回文状态
    for (int i = 0; i < length; ++i)
    {
        // 单个字符构成回文
        p[i][i] = true;
        if (i + 1 < length && src.at(i) == src.at(i + 1))
        {
            p[i][i + 1] = true;
        }
    }

    // 对长度大于3的子串进行判断
   
    for (int len = 3; len <= length; ++len)
    {
        for (int i = 0; i <= length - len; ++i)
        {
            int pre = i;        // 子串起始位置
            int last = i + len - 1; // 子串结束位置

            // 如果子串的起始位置字符相同，则子串是否是回文子串，取决于子串的子串
            if (src.at(pre) == src.at(last) && p[pre + 1][last - 1])
            {
                p[pre][last] = true;
                start = i;
                maxLength = len;
            }
        }
    }

    res = src.substr(start, maxLength);
    return res;
    

   
}

int main()
{
    string s("aaababa");

    cout << DynamicProgramming(s) << endl;

    getchar();
    return 0;

}