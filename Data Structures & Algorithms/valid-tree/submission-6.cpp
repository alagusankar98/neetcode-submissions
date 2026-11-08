#include <cassert>
class DisjointSet {
    private:
        std::vector<int> parent;
    public:
        DisjointSet(int n){
            parent.reserve(n);
            for(int i = 0; i < n; i++){
                parent.push_back(i);
            }
        }

        int find(int i){
            if (parent[i] == i) return i;

            return find(parent[i]);
        }

        bool unify(int u, int v){
            int rootU = find(u);
            int rootV = find(v);

            if(rootU == rootV) return false;

            parent[find(v)] = u;
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
