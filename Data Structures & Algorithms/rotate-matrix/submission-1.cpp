class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());
        
        for(int i = 0; i < (rows) / 2; i++){
            // Swap two rows
            int i_other = rows - i - 1;
            std::swap(matrix[i], matrix[i_other]);
        }

        // Transpose matrix
        for(size_t i = 0; i < rows; i++){
            for(size_t j = i + 1; j < columns; j++){
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};
