/**
如果一个01串任意两个相邻位置的字符都是不一样的,我们就叫这个01串为交错01串。例如: "1","10101","0101010"都是交错01串。
小易现在有一个01串s,小易想找出一个最长的连续子串,并且这个子串是一个交错01串。小易需要你帮帮忙求出最长的这样的子串的长度是多少。 
输入描述:
输入包括字符串s,s的长度length(1 ≤ length ≤ 50),字符串中只包含'0'和'1'


输出描述:
输出一个整数,表示最长的满足要求的子串长度。

输入例子1:
111101111

输出例子1:
3
*/

// 思路：动态规划，最长连续子串

#include <string>
#include <iostream>

using namespace std;

int longestSubSequence(string &s) {
    if(s.size() < 2) {
        return s.size();
    }
    // 字符串拥有最起码一个字符
    int localMax = 1;   // localMax是包含当前字符的最长子串的长度
    int globalMax = 1;  // globalMax是全局最长子串的长度
    for(int i = 1; i < s.size(); ++i) {
        if(s.at(i) != s.at(i-1)) {
            localMax++;
        } else  {
            localMax = 1;
        }
        globalMax = std::max(localMax, globalMax);
    }
    return globalMax;
}

int main() {
    string s;
    cin >> s;
    cout << longestSubSequence(s);
    return 0;
}