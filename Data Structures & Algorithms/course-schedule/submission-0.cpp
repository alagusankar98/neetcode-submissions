#include <cassert>
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.empty()) return true;

        std::vector<int> inDegree(numCourses, 0);
        std::vector<int> offset(numCourses + 1, 0);

        for(const auto& prerequisite : prerequisites){
            const int source_node = prerequisite[1];
            const int destination_node = prerequisite[0];
            assert(source_node >= 0 && source_node < numCourses && destination_node >= 0 && destination_node < numCourses);
            inDegree[destination_node]++;
            offset[source_node + 1]++;
        }

        std::vector<int> bfsVector;
        bfsVector.reserve(numCourses);

        for(int i = 0; i < numCourses; i++){
            if(inDegree[i] == 0) bfsVector.push_back(i);
            offset[i + 1] += offset[i];
        }

        std::vector<int> cursor(offset.begin(), offset.end() - 1);
        std::vector<int> edges(prerequisites.size());

        for(const auto& prerequisite : prerequisites){
            const int source_node = prerequisite[1];
            const int destination_node = prerequisite[0];
            edges[cursor[source_node]] = destination_node;
            cursor[source_node]++;
        }

        int read = 0;
        while(read < static_cast<int>(bfsVector.size())){
            const int sourceIdx = bfsVector[read];
            read++;

            for(int i = offset[sourceIdx]; i < offset[sourceIdx + 1]; i++){
                const int dependentIdx = edges[i];
                if(--inDegree[dependentIdx] == 0) bfsVector.push_back(dependentIdx);
            }
        }

        return (read == numCourses);
    }
};
