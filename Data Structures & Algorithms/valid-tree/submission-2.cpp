#include <cassert>
class Solution {
public:
    bool validTree(int n, const std::vector<std::vector<int>>& edges) {
        if(static_cast<int>(edges.size()) != (n - 1)) return false;

        std::vector<int> offset(n + 1, 0);
        for(const auto& edge : edges){
            assert(edge[0] >= 0 && edge[0] < n && edge[1] >= 0 && edge[1] < n);
            offset[edge[0]]++;
            offset[edge[1]]++;
        }

        for(int i = 0; i < n; i++){
            offset[i + 1] += offset[i];
        }

        std::vector<int> edgeVector(2 * edges.size(), 0);
        for(const auto& edge : edges){
            edgeVector[--offset[edge[0]]] = edge[1];
            edgeVector[--offset[edge[1]]] = edge[0];
        }

        std::vector<std::pair<int,int>> bfsVector;
        bfsVector.reserve(n);
        std::vector<uint8_t> seen(n, 0);
        
        bfsVector.emplace_back(0, -1);
        seen[0] = 1;
        int read = 0;
        while(read < static_cast<int>(bfsVector.size())){
            const auto [sourceIdx, pushIdx] = bfsVector[read];
            read++;

            for(int i = offset[sourceIdx]; i < offset[sourceIdx + 1]; i++){
                const int connectedNodeIdx = edgeVector[i];
                if(seen[connectedNodeIdx]){
                    // We know sourceIdx->connectedIdx connection exists
                    // Check if connectedIdx is the same node that pushed sourceIdx here
                    if(connectedNodeIdx != pushIdx) return false;
                } else {
                    bfsVector.emplace_back(connectedNodeIdx, sourceIdx);
                    seen[connectedNodeIdx] = 1;
                }
            }
        }
        return (read == n);
    }
};
