/**
 * 给定一个二维矩阵的行和列，以及一系列的ops操作。每个操作包含两个数a, b
 * 每个操作将 0<=i<a, 0<=j<b范围内的矩阵[i][j]位置的数+1
 * 要求找到最终矩阵中数字最大的数的个数。
 */

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto &v : ops)
        {
            m = min(m, v.at(0));
            n = min(n, v.at(1));
        }
        return m * n;
    }
};