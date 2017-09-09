#include <vector>
#include <string>
#include <iostream>

using namespace std;

void generate_parenthesis_helper(vector<string> &v, string s, int l, int r) // l和r记录剩余左右括号的数量
{
    // 当且仅当左右括号数量都为0时，正常结束
    if(l == 0 && r == 0)
    {
        v.emplace_back(s);
    }

    //  括号要想匹配，首先应该压入左括号，再压入右括号
    if(l > 0)
    {
        generate_parenthesis_helper(v, s + "(", l - 1, r);
    }

    //  压入右括号时候，必须保证左括号数多，即有左括号在解集中
    if(r > 0 && l < r) // 剩余的右括号数量比左括号多时才能添加右括号
    {
        generate_parenthesis_helper(v, s + ")", l, r - 1);
    }
}

vector<string> generate_parenthsis(int n) {
    vector<string> result;
    generate_parenthesis_helper(result, "", n, n);
    return result;
}


int main() {
    int n = 3;
    vector<string> ss =  generate_parenthsis(n);

    for(auto &s: ss) {
        cout << s << endl;
    }
    getchar();
    return 0;
}