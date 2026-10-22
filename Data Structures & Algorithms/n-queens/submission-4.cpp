class Solution {
public:
    void boardGenerator(std::vector<std::vector<std::string>>& resultVector, std::vector<std::string>& currentBoard, int n, std::array<bool, 9>& colUsed, std::array<bool, 17>& diagonalLeftUsed, std::array<bool, 17>& diagonalRightUsed, int rowIdx){
        if(rowIdx >= n){
            resultVector.push_back(currentBoard);
            return;
        }

        for(int i = 0; i < n; i++){
            int diagLeftIdx = rowIdx + i;
            int diagRightIdx = rowIdx - i + std::ssize(colUsed) - 1;
            if(!(colUsed[i] || diagonalLeftUsed[diagLeftIdx] || diagonalRightUsed[diagRightIdx])){
                currentBoard.emplace_back(n, '.');
                currentBoard.back()[i] = 'Q';

                // Mark Queen positions in 3 directions
                colUsed[i] = true;
                diagonalLeftUsed[diagLeftIdx] = true;
                diagonalRightUsed[diagRightIdx] = true;


                boardGenerator(resultVector, currentBoard, n, colUsed, diagonalLeftUsed, diagonalRightUsed, rowIdx + 1);
                currentBoard.pop_back();

                // Unmark Queen positions in 3 directions
                colUsed[i] = false;
                diagonalLeftUsed[diagLeftIdx] = false;
                diagonalRightUsed[diagRightIdx] = false;
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> resultVector;
        std::vector<std::string> currentBoard;
        std::array<bool, 9> colUsed{};
        std::array<bool, 17> diagonalLeftUsed{};
        std::array<bool, 17> diagonalRightUsed{};
        currentBoard.reserve(n);
        boardGenerator(resultVector, currentBoard, n, colUsed, diagonalLeftUsed, diagonalRightUsed, 0);
        return resultVector;
    }
};
