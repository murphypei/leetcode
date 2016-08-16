/**
 * 剑指offer面试题
 * 替换字符串中的空格为"%20"
 *
 * 难点：字符串是连续存储的, 替换的字符会比原先的字符多, 存在覆盖问题
 * 
 * 如果可以开辟空间, 则采用指针遍历旧字符串, 将指针内容存入新字符串, 遇到空格替换为"%20" , O(n)
 *
 * 如果不能开辟空间, 则原字符串肯定有空余空间, 先遍历算出替换后所需空间, 然后使用两个指针, 从后向前遍历替换
 */

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    void replace(string &str, const string &rp) {
        typedef string::size_type ssize;
        ssize i = 0;
        ssize count = 0;
        while(i != str.size()) {
            if(str[i] == ' ')
                count += rp.size();
            else
                count += 1;
            i++;
        }
        
        if(str.size() < count)
            str.resize(count);
        
        i--;                     // 替换前字符串最后一位
        ssize j = count - 1 ;    // 替换后的字符串最后一位
        while(i >= 0 && j >=0 && i != j) {
            if(str[i] != ' ') {
                str[j--] = str[i--];
            }
            else {
                str[j--] = '0';
                str[j--] = '2';
                str[j--] = '%';
                i--;
            }
        }
    }
};


int main() {

    string str("We are happy.");
    Solution solution;
    solution.replace(str, "%20");
    cout << str << endl;

    return 0;
}