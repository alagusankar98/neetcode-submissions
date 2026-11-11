#include <numeric>
class DisjointSet {
    private:
        std::vector<int> parent_;
        std::vector<int> size_;
    public:
        DisjointSet(int n) : parent_(n), size_(n, 1) {
            std::iota(parent_.begin(), parent_.end(), 0);
        }

        int find(int i){
            if(i == parent_[i]) return i;

            return parent_[i] = find(parent_[i]);
        }

        bool unite(int u, int v){
            int rootU = find(u);
            int rootV = find(v);

            if(rootU == rootV) return false;

            if(size_[rootU] > size_[rootV]){
                parent_[rootV] = rootU;
                size_[rootU] += size_[rootV];
            } else {
                parent_[rootU] = rootV;
                size_[rootV] += rootU;
            }

            return true;
        }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        const int n = static_cast<int>(grid.size());
        if(n == 1) return grid[0][0];

        std::vector<int> positions(n*n, 0);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                positions[grid[i][j]] = i * n + j;
            }
        }

        static constexpr std::array<std::pair<int, int>, 4> directionArray = {{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        DisjointSet dsu(n*n);
        int initialNode = grid[0][0];
        int endNode = grid[n - 1][n - 1];

        for(int t = 0; t < (n * n); t++){
            int r = positions[t] / n;
            int c = positions[t] % n;

            for(const auto& [rowOffset, colOffset] : directionArray){
                if(int rowIdx = (r + rowOffset), colIdx = (c + colOffset); 
                (rowIdx >= 0 && rowIdx < n && colIdx >= 0 && colIdx < n && (grid[rowIdx][colIdx] < t))){
                    if(dsu.unite(t, grid[rowIdx][colIdx]) && t >= initialNode && t >= endNode && (dsu.find(initialNode) == dsu.find(endNode))){
                        return t;
                    }
                }
            }
        }
    }
};
