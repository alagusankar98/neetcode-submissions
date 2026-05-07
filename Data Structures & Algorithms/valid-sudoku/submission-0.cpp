class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Check rows
        for(size_t i = 0; i < board.size(); i++){
            std::array<bool, 10> digitArray{false};
            for(size_t j = 0; j < board[i].size(); j++){
                if(board[i][j] >= '1' && board[i][j] <= '9'){
                    int val = board[i][j] - '0';
                    if(digitArray[val]) return false;
                    digitArray[val] = true;
                }
            }
        }

        // Check columns
        for(size_t i = 0; i < board.size(); i++){
            std::array<bool, 10> digitArray{false};
            for(size_t j = 0; j < board[i].size(); j++){
                if(board[j][i] >= '1' && board[j][i] <= '9'){
                    int val = board[j][i] - '0';
                    if(digitArray[val]) return false;
                    digitArray[val] = true;
                }
            }
        }

        // Mini squares
        for(size_t i = 0; i < board.size(); i++){
            std::array<bool, 10> digitArray{false};
            for(size_t j = 0; j < board[i].size(); j++){
                auto row = (j / 3) + (3 * (i % 3)) ;
                auto column = (j % 3) + (3 * (i / 3));
                if(board[row][column] >= '1' && board[row][column] <= '9'){
                    int val = board[row][column] - '0';
                    if(digitArray[val]) return false;
                    digitArray[val] = true;
                }
            }
        }
        return true;
    }
};
