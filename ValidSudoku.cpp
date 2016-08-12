// Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

// The Sudoku board could be partially filled, where empty cells are filled with the character '.'.



class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        size_t length = board.size();
        
        int row, column;
        unordered_map<int, int> row_mp;
        unordered_map<int, int> column_mp;
        unordered_map<int, int> block_mp;
        for(row = 0; row < length; ++row) {
            row_mp.clear();
            column_mp.clear();
            
            for(column = 0; column < length; ++column) {
                if(row%3 == 0 && column%3 == 0) {       // 判断九宫格
                    block_mp.clear();
                    for(int i = 0; i < 3; ++i)
                        for(int j = 0; j < 3; ++j) {
                            if(board[row + i][column + j] != '.') {
                                ++block_mp[board[row + i][column + j]];
                                if(block_mp[board[row + i][column + j]] > 1)
                                    return false;
                            }
                        }
                }
                
                if(board[row][column] != '.') {       // 判断行元素
                    ++row_mp[board[row][column]];
                    if(row_mp[board[row][column]] > 1)
                        return false;
                }
                
                if(board[column][row] != '.') {       // 判断列元素
                    ++column_mp[board[column][row]];
                    if(column_mp[board[column][row]] > 1)
                        return false;
                }
            } 
        }
        
        return true;
    }
};