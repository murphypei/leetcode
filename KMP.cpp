
// KMP算法要点：
// 
// 移动位数 = 已匹配的字符数 - 对应的部分匹配值
// 
// 部分匹配值就是一个字符串"s0s1s2.....sn"(已匹配的字符构成)的前缀和后缀的最长共有元素的长度
// 
// 先求目标子串的匹配值表, 然后进行匹配, 匹配过程中, 根据匹配值表和已匹配字符数来移动
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 构建匹配值表
// match_table下标表示已匹配的字符数, 所以从1开始
// match_table元素表示已匹配的字符个数对应的部分匹配值
// pattern要匹配的子串
void buildMatchTable(vector<int>& match_table, string& pattern) {
    // 已匹配的字符数
    size_t i = 0;
    // 部分匹配值       
    int match_value = -1;
    match_table[i] = match_value;
    while (i != pattern.size()) {
        // 如果已匹配了n个字符, match_value=n, 因为字符串下标从0开始, 说明0~match_value-1已匹配, 则pattern[i]需要匹配pattern[match_value]
        // 如果该位置不匹配, 则需要将match_value修改为第match_value的部分匹配值 
        while(match_value != -1  && pattern[i] != pattern[match_value])
            match_value = match_table[match_value];
        
        // 如果匹配, match_value加1, table指向下一个字符
        match_table[++i] = ++match_value; 
    }
}



// leetcode strStr
// needle is pattern
int strStr(string haystack, string needle) {
    if(haystack.empty())
        return needle.empty() ? 0 : -1;
    if(needle.empty())
        return 0;
    
    vector<int> match_table(needle.size() + 1);
    buildMatchTable(match_table, needle);
    for(int i = 0; i < match_table.size(); ++i)
        cout << "match_table[" << i << "]=" << match_table[i] << endl;
    size_t i = 0, j = 0;
    while(i != haystack.size()) {
        cout << "i=" << i << "   j=" << j << endl;
        
        // 不匹配
        while(j != -1 && haystack[i] != needle[j])
            j = match_table[j];     // 更改j的值
        
        // 匹配
        ++i;
        ++j;
        
        // 完全匹配整个pattern
        if(j == needle.size())
            return i - j;
    }

    return -1;
}


int main() {
    string target("BBC ABCDAB ABCDABCDABDE");
    string pattern("ABCDABD");

    int res = strStr(target, pattern);
    cout << res << endl;

    return 0;
}