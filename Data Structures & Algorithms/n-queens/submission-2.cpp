class Solution {
public:
    bool isQueenPositionValid(const std::vector<bool>& colUsed, const std::vector<bool>& diagonalLeftUsed, const std::vector<bool>& diagonalRightUsed, int rowIdx, int colIdx){
        // Given an already existing valid board with queens
        // check if new position is valid

        return !(colUsed[colIdx] || diagonalLeftUsed[rowIdx + colIdx] || diagonalRightUsed[rowIdx - colIdx + std::ssize(colUsed) - 1]) ;
    }

    void boardGenerator(std::vector<std::vector<std::string>>& resultVector, std::vector<std::string>& currentBoard, int n, std::vector<bool>& colUsed, std::vector<bool>& diagonalLeftUsed, std::vector<bool>& diagonalRightUsed, int rowIdx){
        if(rowIdx >= n){
            resultVector.push_back(currentBoard);
            return;
        }

        for(int i = 0; i < n; i++){
            if(isQueenPositionValid(colUsed, diagonalLeftUsed, diagonalRightUsed, rowIdx, i)){
                currentBoard.emplace_back(n, '.');
                currentBoard.back()[i] = 'Q';

                // Mark Queen positions in 3 directions
                colUsed[i] = true;
                diagonalLeftUsed[rowIdx + i] = true;
                diagonalRightUsed[rowIdx - i + std::ssize(colUsed) - 1] = true;


                boardGenerator(resultVector, currentBoard, n, colUsed, diagonalLeftUsed, diagonalRightUsed, rowIdx + 1);
                currentBoard.pop_back();

                // Unmark Queen positions in 3 directions
                colUsed[i] = false;
                diagonalLeftUsed[rowIdx + i] = false;
                diagonalRightUsed[rowIdx - i + std::ssize(colUsed) - 1] = false;
            }
        }
    }

    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> resultVector;
        std::vector<std::string> currentBoard;
        std::vector<bool> colUsed(n, false);
        std::vector<bool> diagonalLeftUsed((2*n - 1), false);
        std::vector<bool> diagonalRightUsed((2*n - 1), false);
        currentBoard.reserve(n);
        boardGenerator(resultVector, currentBoard, n, colUsed, diagonalLeftUsed, diagonalRightUsed, 0);
        return resultVector;
    }
};
