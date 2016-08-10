// Given numRows, generate the first numRows of Pascal's triangle.

// For example, given numRows = 5,
// Return

// [
//      [1],
//     [1,1],
//    [1,2,1],
//   [1,3,3,1],
//  [1,4,6,4,1]
// ]


/**
 * 杨辉三角
 * 思路：除了首尾以外, 其余部分的规律：current[j] = last[j] + last[j-1]
 */
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<int> current;
        vector<int> last;
        vector<vector<int> > result;
        
        result.clear();
        if(numRows == 0)
            return result;
        
        for(int i = 0; i < numRows; ++i) {
            current.clear();
            cout << "*" << i << endl;
            for(int j = 0; j <= i; ++j) {
                if(j == 0) {
                    current.push_back(1);
                }
                else if(j == i){
                    current.push_back(1);
                }
                else {
                    current.push_back(last[j] + last[j-1]);
                }
                cout << current[j] << endl;
            }
            cout << "----" << endl;
            last = current;
            result.push_back(current);
        }
        return result;
    }

};


int main() {
    Solution s;
    vector<vector<int> > result = s.generate(4);
}