/*
给定一个无序矩阵，其中只有1和0两种值，求只含有1的最大正方形的大小。
例如给定如下矩阵:
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 4
*/

// 思路：采用动态规划，从左上角开始，考察每个点在其周围点所形成的矩阵的基础上，所能够形成的矩阵的大小
// 观察正方形的结构，可以得到动态规划的公式。

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

int max_square(vector<vector<char>>& matrix) {
    if(matrix.empty()) {
        return 0;
    }
    
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxLen = 0;

    vector<vector<int>> res(rows + 1, vector<int>(cols + 1, 0));
    for(int i = 1; i <= rows; ++i) {
        for(int j = 1; j <= cols; ++j) {
            if(matrix[i-1][j-1] == '0') {
                res[i][j] = 0;
            } else {
                res[i][j] = min(res[i-1][j-1], min(res[i-1][j], res[i][j-1])) + 1;
                if(res[i][j] > maxLen) {
                    maxLen = res[i][j];
                }
            }
        }
    }
    return maxLen * maxLen;

}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> matrix(n, vector<char>(m, '0'));
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << max_square(matrix) << endl;

    getchar();
    return 0;
}


