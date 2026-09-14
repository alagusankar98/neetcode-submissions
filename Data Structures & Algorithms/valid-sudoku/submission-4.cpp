class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<uint16_t, 9> columnFlags{};
        std::array<uint16_t, 9> rowFlags{};
        std::array<uint16_t, 9> boxFlags{};

        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[i].size(); j++){
                if (board[i][j] == '.') continue;
                
                uint8_t digit = board[i][j] - '1';
                size_t currentBoxIdx = 3 * (j / 3) + (i/3);

                // Check Row flag
                if((((rowFlags[i] | columnFlags[j] | boxFlags[currentBoxIdx]) >> digit) & 1) > 0){
                    return false;
                }

                rowFlags[i] = rowFlags[i] | (1 << digit);
                columnFlags[j] = columnFlags[j] | (1 << digit);
                boxFlags[currentBoxIdx] = boxFlags[currentBoxIdx] | (1 << digit);
            }
        }
        return true;
    }
};
