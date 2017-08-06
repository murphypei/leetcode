/**
 * 最长公共子串(不是子序列，必须连续)
 *
 * 动态规划的思想：假设两个字符串分别为s和t，s[i]和t[j]分别表示其第i和第j个字符(字符顺序从0开始)，
 * 再令L[i, j]表示以s[i]和s[j]为结尾的相同子串的最大长度。应该不难递推出L[i, j]和L[i+1,j+1]之间
 * 的关系，因为两者其实只差s[i+1]和t[j+1]这一对字符。若s[i+1]和t[j+1]不同，那么L[i+1, j+1]自然
 * 应该是0，因为任何以它们为结尾的子串都不可能完全相同；而如果s[i+1]和t[j+1]相同，那么就只要在以
 * s[i]和t[j]结尾的最长相同子串之后分别添上这两个字符即可，这样就可以让长度增加一位。合并上述两种
 * 情况，也就得到L[i+1,j+1]=(s[i]==t[j]?L[i,j]+1:0)这样的关系。
 *
 * 最长公共子序列的递推公式：
    - 如果str1[m] == str2[n]，则L[m,n] = L[m - 1, n -1] + 1；
    - 如果str1[m] != str2[n]，则L[m,n] = max{L[m,n - 1]，L[m - 1, n]}
 */

#include <vector>
#include <iostream>
#include <string>

#define IDER_DEBUG

using namespace std;


int LongestCommonSubString(const string& str1, const string& str2) {
    size_t size1 = str1.size();
    size_t size2 = str2.size();

    if(size1 == 0 || size2 == 0) {
        return 0;
    }

    // table记录L[i, j]
    vector<vector<int> > table(size1, vector<int>(size2, 0));

    // 初始化table，str2每个字符和str1[0]比较
    for(int j = 0; j < size2; ++j) {
        table[0][j] = (str1[0] == str2[j] ? 1 : 0);
    }

    // 动态规划求解
    for(int i = 1; i < size1; ++i) {
        table[i][0] = (str1[i] == str2[0] ? 1 : 0);
        for(int j = 1; j < size2; ++j) {
            if(str1[i] == str2[j]) {
                table[i][j] = table[i-1][j-1]+1;
            }
        }
    }


    int start1 = -1;        // 公共子串在str1中起始位置
    int start2 = -1;        // 公共子串在str1中起始位置
    int longest = 0;        // 公共子串长度
    for(int i = 0; i < size1; ++i){
        for(int j = 0; j < size2; ++j) {
            if(longest < table[i][j]) {
                longest = table[i][j];
                start1 = i - longest + 1;
                start2 = j - longest + 1;
            }
        }
    }

#ifdef IDER_DEBUG
    cout<< "(first, second, longest) = (" 
    << start1 << ", " << start2 << ", " << longest
    << ")" << endl;
#endif

    return longest;
}

int main() {

    string str1 = "asdfhgjh";
    string str2 = "eweifhgjade";

    cout << LongestCommonSubString(str1, str2) << endl;
    getchar();
    return 0;
}