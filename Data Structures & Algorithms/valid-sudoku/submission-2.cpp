class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<uint16_t, 9> rows{0};
        std::array<uint16_t, 9> columns{0};
        std::array<uint16_t, 9> boxes{0};
        
        // Check rows
        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[i].size(); j++){
                if(board[i][j] < '1' || board[i][j] > '9'){
                    continue;
                }
                int val = board[i][j] - '0' - 1;

                // Row Check
                if((rows[i] & (1 << val) ) > 0) return false; // Check bit value for 'val' position
                rows[i] |= 1 << val; // Set bit value to true for 'val' position

                // Column Check
                if((columns[j] & (1 << val) ) > 0) return false;
                columns[j] |= 1 << val;

                // Mini-Boxes check
                auto boxPos = (j / 3) + (3 * (i / 3));
                if((boxes[boxPos] & (1 << val) ) > 0) return false;
                boxes[boxPos] |= 1 << val;
            }
        }
        return true;
    }
};
