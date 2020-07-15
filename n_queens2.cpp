#include <algorithm>
#include <vector>

class Solution
{
public:
    int totalNQueens(int n)
    {
        int result = 0;
        std::vector<int> queenColPos(n, -1);
        findColPos(0, n, queenColPos, result);
        return result;
    }

    void findColPos(int curRow, int n, std::vector<int> &queenColPos, int &result)
    {
        if (curRow == n)
        {
            // find a solution
            result++;
            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (isValid(curRow, i, queenColPos))
            {
                queenColPos[curRow] = i;
                findColPos(curRow + 1, n, queenColPos, result);
                // backtrace
                queenColPos[curRow] = -1;
            }
        }
    }
    bool isValid(int curRow, int curCol, std::vector<int> &queenColPos)
    {
        for (int i = 0; i < curRow; ++i)
        {
            // same column in different rows or diagonal is invalid.
            if (queenColPos[i] == curCol || std::abs(curCol - queenColPos[i]) == curRow - i)
            {
                return false;
            }
        }
        return true;
    }
};