class Solution {
public:
    bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
        if(matrix.empty() || matrix[0].empty()) return false;
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());

        int left = 0;
        int right = (rows * cols) - 1;

        while(left <= right){
            int mid = left + (right - left) / 2;

            // Convert mid back to rows and columns
            int row = (mid / cols);
            int column = (mid % cols);

            if(matrix[row][column] == target){
                return true;
            } else if (matrix[row][column] > target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return false;
    }
};
