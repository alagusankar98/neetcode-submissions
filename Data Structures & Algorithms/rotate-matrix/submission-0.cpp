class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        int rows = static_cast<int>(matrix.size());
        int columns = static_cast<int>(matrix[0].size());
        
        for(int i = 0; i < (rows + 1) / 2; i++){
            // Swap two rows
            int i_other = rows - i - 1;
            for(size_t j = 0; j < columns; j++){
                std::swap(matrix[i][j], matrix[i_other][j]);
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[i_other][j];
                // matrix[i_other][j] = temp;
            }
        }

        // Transpose matrix
        for(size_t i = 0; i < rows; i++){
            for(size_t j = 0; j < i; j++){
                std::swap(matrix[i][j], matrix[j][i]);
                // int temp = matrix[i][j];
                // matrix[i][j] = matrix[j][i];
                // matrix[j][i] = temp;
            }
        }
    }
};
