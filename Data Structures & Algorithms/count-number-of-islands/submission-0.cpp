class Solution {
public:
    void countIslands(const std::vector<std::vector<char>>& grid, std::vector<std::vector<bool>>& seen, int i, int j, const std::array<std::pair<int, int>, 4>& directionArray){
        int rows = std::ssize(grid);
        int columns = std::ssize(grid[0]);

        if((i < 0) || (j < 0) || (i >= rows) || (j >= columns) || seen[i][j] || grid[i][j] != '1') return;

        seen[i][j] = true;

        for(const auto& [r, c] : directionArray){
            countIslands(grid, seen, i + r, j + c, directionArray);
        }
    }

    int numIslands(const std::vector<std::vector<char>>& grid) {
        if(grid.empty()) return 0;
        std::vector<std::vector<bool>> seen(grid.size(), std::vector<bool>(grid[0].size(), false));
        std::array<std::pair<int, int>, 4> directionArray = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
        int count = 0;
        for(std::size_t i = 0; i < grid.size(); i++){
            for(std::size_t j = 0; j < grid[i].size(); j++){
                if (grid[i][j] == '1' && !seen[i][j]){
                    countIslands(grid, seen, i, j, directionArray);
                    count++;
                }
            }
        }

        return count;
    }
};
