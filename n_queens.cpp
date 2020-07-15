#include <string>
#include <vector>
class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> results;
        std::vector<int> queenColPos(n, -1);
        findPosBackTrace(0, n, queenColPos, results);
        return results;
    }

    // backtrace for find a column position for current row.
    void findPosBackTrace(int curRow, int N, std::vector<int> &queenColPos, std::vector<std::vector<std::string>> &results)
    {
        // generate result string
        if (curRow == N)
        {
            std::vector<std::string> out(N, std::string(N, '.'));
            for (int i = 0; i < N; ++i)
            {
                out[i][queenColPos[i]] = 'Q';
            }
            results.emplace_back(out);
            return;
        }

        for (int i = 0; i < N; ++i)
        {
            if (isValidPos(curRow, i, queenColPos))
            {
                queenColPos[curRow] = i;
                findPosBackTrace(curRow + 1, N, queenColPos, results);
                // backtrace point
                queenColPos[curRow] = -1;
            }
        }
    }

    // verify valid position
    bool isValidPos(int curRow, int curCol, std::vector<int> &queenColPos)
    {
        for (int i = 0; i < curRow; ++i)
        {
            if (queenColPos[i] == curCol || std::abs(curCol - queenColPos[i]) == curRow - i)
            {
                return false;
            }
        }
        return true;
    }
};