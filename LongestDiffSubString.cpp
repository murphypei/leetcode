/**
 * 动态规划求最长的连续不重复子串
 */

 
#include <unordered_set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string s = "abcdabecdf";
    vector<int> table(s.size(), 1);
    vector<char> chset;
    for(int i = 0; i < s.size(); ++i) {
        if(i == 0) {
            chset.push_back(s[i]);
            continue;
        }
        auto it = find(chset.begin(), chset.end(), s[i]);
        if(it != chset.end()) {
            chset = vector<char>(++it, chset.end());
            chset.push_back(s[i]);
            table[i] = chset.size();
        } else {
            table[i] = table[i-1] + 1;
            chset.push_back(s[i]);
        }
        cout << "i: " << i << " : ";
        copy(chset.begin(), chset.end(), ostream_iterator<char>(cout, " "));
        cout << endl;
    }

    copy(table.begin(), table.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    return 0;

}