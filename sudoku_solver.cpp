#include <vector>

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        backtrace(board, 0, 0);
    }

    bool backtrace(std::vector<std::vector<char>> &board, int curRow, int curCol)
    {
        if (curRow >= 9)
        {
            return true;
        }
        if (curCol >= 9)
        {
            return backtrace(board, curRow + 1, 0);
        }
        if (board[curRow][curCol] != '.')
        {
            return backtrace(board, curRow, curCol + 1);
        }

        for (int n = 0; n < 9; ++n)
        {
            if (isValid(board, curRow, curCol, '1' + n))
            {
                board[curRow][curCol] = '1' + n;
                // 这个地方的判断非常重要。我们用DFS递归调用了下一个位置，只有这个递归调用返回时true，说明整个搜索结束了，则直接返回true，否则需要重置此处的val，继续搜索下一个val。
                // 如果进行判断，我们无法判断此处的val是否是真正的有效解的一部分，仅仅调用DFS无法搜出正确的结果。
                if (backtrace(board, curRow, curCol + 1))
                {
                    return true;
                }
                // clean for the next search
                board[curRow][curCol] = '.';
            }
        }
        return false;
    }

    bool isValid(std::vector<std::vector<char>> &board, int curRow, int curCol, char val)
    {
        // No repeat in same row or column
        for (int i = 0; i < 9; ++i)
        {
            if (board[curRow][i] == val || board[i][curCol] == val)
                return false;
        }
        // No repeat in sub matrix
        // find start row and column of current position
        int subRow = curRow - curRow % 3, subCol = curCol - curCol % 3;
        for (int i = 0; i < 3; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                if (board[subRow + i][subCol + j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }
};