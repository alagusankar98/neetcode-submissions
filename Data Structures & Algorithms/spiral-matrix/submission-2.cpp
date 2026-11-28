class Solution {
public:
    vector<int> spiralOrder(const std::vector<vector<int>>& matrix) {
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        const size_t n = rows * cols;
        int top = 0;
        int left = 0;
        int bottom = rows - 1;
        int right = cols - 1;

        std::vector<int> spiralVector;
        spiralVector.reserve(n);

        while(spiralVector.size() < n) {
            for(int j = left; j <= right && top <= bottom; j++){
                spiralVector.push_back(matrix[top][j]);
            }
            top++;

            for(int i = top; i <= bottom && left <= right; i++){
                spiralVector.push_back(matrix[i][right]);
            }
            right--;

            for(int j = right; j >= left && top <= bottom; j--){
                spiralVector.push_back(matrix[bottom][j]);
            }
            bottom--;

            for(int i = bottom; i >= top && left <= right; i--){
                spiralVector.push_back(matrix[i][left]);
            }
            left++;
        }
        return spiralVector;
    }
};
