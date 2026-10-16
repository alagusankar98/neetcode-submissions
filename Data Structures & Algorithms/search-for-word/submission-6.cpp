class Solution {
public:
    bool wordSearch(const std::vector<std::vector<char>>& board, std::vector<std::vector<bool>>& seen, std::string_view word, size_t searchIdx, int i, int j){
        if(searchIdx >= word.size()) return true;

        // Check boundary validity and word match
        if((i < 0) || (j < 0) || (i >= board.size() || (j >= board[0].size()) || seen[i][j] || board[i][j] != word[searchIdx])) return false;

        seen[i][j] = true;

        bool resultFlag = wordSearch(board, seen, word, searchIdx + 1, i + 1, j) || wordSearch(board, seen, word, searchIdx + 1, i - 1, j) || wordSearch(board, seen, word, searchIdx + 1, i, j + 1) || wordSearch(board, seen, word, searchIdx + 1, i, j - 1);
        seen[i][j] = false;
        return resultFlag;
    }
    bool exist(const std::vector<std::vector<char>>& board, std::string_view word) {
        std::vector<std::vector<bool>> seen(board.size(), std::vector<bool>(board[0].size(), false));
        for(size_t i = 0; i < board.size(); i++){
            for(size_t j = 0; j < board[i].size(); j++){
                if(wordSearch(board, seen, word, 0, i, j)) return true;
            }
        }
        return false;
    }
};
