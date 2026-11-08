#include <cassert>
class DisjointSet {
    private:
        std::vector<int> parent_;
        std::vector<std::size_t> size_;
    public:
        DisjointSet(int n){
            parent_.reserve(n);
            size_.reserve(n);
            for(int i = 0; i < n; i++){
                parent_.push_back(i);
                size_.push_back(0);
            }
        }

        int find(int i){
            if (parent_[i] == i) return i;

            return parent_[i] = find(parent_[i]);
        }

        bool unify(int u, int v){
            int rootU = find(u);
            int rootV = find(v);

            if(rootU == rootV) return false;

            if(size_[rootU] > size_[rootV]){
                parent_[rootU] = rootV;
                size_[rootU]++;
            } else {
                parent_[rootV] = rootU;
                size_[rootV]++;
            }

            return true;
        }
};
class Solution {
public:
    bool validTree(int n, const std::vector<std::vector<int>>& edges) {
        if(static_cast<int>(edges.size()) != (n - 1)) return false;

        DisjointSet obj(n);
        for(const auto& edge : edges){
            assert(edge[0] >= 0 && edge[0] < n && edge[1] >= 0 && edge[1] < n);
            if(!obj.unify(edge[0], edge[1])) return false;
        }
        return true;
    }
};
