#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    bool exist(vector<vector<char>> &board, string word)
    {
        if (word.empty())
        {
            return true;
        }
        else if (board.empty() || board[0].empty())
        {
            return false;
        }

        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (board[i][j] == word[0])
                {
                    used[i][j] = true;
                    bool res = dfs_search(i, j, 1, word, board, used);
                    if (res)
                    {
                        return true;
                    }
                    else
                    {
                        used[i][j] = false;
                    }
                }
            }
        }
        return false;
    }

    bool dfs_search(int row, int col, int index, const string &word, const vector<vector<char>> &board,
                    vector<vector<bool>> &used)
    {
        if (index == word.size())
        {
            return true;
        }

        if (row - 1 >= 0 && !used[row - 1][col] && board[row - 1][col] == word[index])
        {
            used[row - 1][col] = true;
            if (dfs_search(row - 1, col, index + 1, word, board, used))
            {
                return true;
            }
            else
            {
                used[row - 1][col] = false;
            }
        }
        if (row + 1 < board.size() && !used[row + 1][col] && board[row + 1][col] == word[index])
        {
            used[row + 1][col] = true;
            if (dfs_search(row + 1, col, index + 1, word, board, used))
            {
                return true;
            }
            else
            {
                used[row + 1][col] = false;
            }
        }
        if (col - 1 >= 0 && !used[row][col - 1] && board[row][col - 1] == word[index])
        {
            used[row][col - 1] = true;
            if (dfs_search(row, col - 1, index + 1, word, board, used))
            {
                return true;
            }
            else
            {
                used[row][col - 1] = false;
            }
        }
        if (col + 1 < board[0].size() && !used[row][col + 1] && board[row][col + 1] == word[index])
        {
            used[row][col + 1] = true;
            if (dfs_search(row, col + 1, index + 1, word, board, used))
            {
                return true;
            }
            else
            {
                used[row][col + 1] = false;
            }
        }
        return false;
    }
};