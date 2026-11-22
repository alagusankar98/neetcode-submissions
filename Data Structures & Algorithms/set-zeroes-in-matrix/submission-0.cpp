class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if(matrix.empty()) return;
        const int rows = static_cast<int>(matrix.size());
        const int cols = static_cast<int>(matrix[0].size());
        std::vector<std::pair<int, int>> bfs;
        bfs.reserve(rows*cols);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] == 0) bfs.emplace_back(i, j);
            }
        }

        size_t read = 0;
        while(read < bfs.size()) {
            auto [r, c] = bfs[read]; read++;

            for(int i = 0; i < rows; i++) matrix[i][c] = 0;
            for(int j = 0; j < cols; j++) matrix[r][j] = 0;
        }
    }
};
