class Solution {
public:
    int longestIncreasingPathHelper(const std::vector<std::vector<int>>& matrix, int i, int j, std::vector<std::vector<int>>& dp) {
        if(dp[i][j] != -1) return dp[i][j];
        static constexpr std::array<std::pair<int, int>, 4> directionArray = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        const int rows = static_cast<int>(matrix.size());
        const int columns = static_cast<int>(matrix[0].size());

        int count = 1;
        for(const auto& [r, c] : directionArray) {
            if(int rowIdx = (i + r), colIdx = (j + c); rowIdx >= 0 && colIdx >= 0 && rowIdx < rows && colIdx < columns && matrix[rowIdx][colIdx] > matrix[i][j]) {
                count = std::max(count, 1 + longestIncreasingPathHelper(matrix, rowIdx, colIdx, dp));
            }
        }
        return dp[i][j] = count;
    }
    int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
        const int rows = static_cast<int>(matrix.size());
        const int columns = static_cast<int>(matrix[0].size());
        std::vector<std::vector<int>> dp(rows, std::vector<int>(columns, -1));
        int count = 0;
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < columns; j++) {
                count = std::max(count, longestIncreasingPathHelper(matrix, i, j, dp));
            }
        }
        return count;
    }
};
