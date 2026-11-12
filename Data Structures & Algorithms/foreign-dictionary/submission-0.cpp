class Solution {
public:
    std::string foreignDictionary(const std::vector<std::string>& words) {
        uint32_t nodes = 0;
        std::array<int, 26> inDegree{};
        std::array<int, 27> offset{};
        std::vector<std::pair<int, int>> edgePairVector;
        edgePairVector.reserve(words.size());
        for(size_t i = 0; i < words.size(); i++){
            for(size_t j = 0; j < words[i].size(); j++){
                nodes |= (1u << (words[i][j] - 'a'));
            }

            if(i < 1) continue;

            std::size_t minSize = std::min(words[i].size(), words[i-1].size());
            std::size_t j = 0;
            while((j < minSize) && (words[i][j] == words[i-1][j])) j++;

            if(j == minSize){
                if(words[i-1].size() > words[i].size()) return "";
                continue;
            }

            // Edge formation
            edgePairVector.emplace_back(words[i-1][j] - 'a', words[i][j] - 'a');
            inDegree[words[i][j] - 'a']++;
            offset[words[i-1][j] - 'a']++;
        }

        const int n = std::popcount(nodes);
        std::string resultString;
        resultString.reserve(n);

        for(unsigned int i = 0; i < 26; i++){
            offset[i+1] += offset[i];
            if(((nodes >> i) & 1) && inDegree[i] == 0) resultString.push_back(i + 'a');
        }

        std::vector<int> edges(edgePairVector.size(), 0);
        for(const auto& [sourceNode, destinationNode] : edgePairVector){
            edges[--offset[sourceNode]] = destinationNode;
        }

        int read = 0;
        while(read < static_cast<int>(resultString.size())){
            int sourceNode = resultString[read] - 'a';
            read++;

            for(int i = offset[sourceNode]; i < offset[sourceNode + 1]; i++){
                if(--inDegree[edges[i]] == 0) resultString.push_back(edges[i] + 'a');
            }
        }

        if(read != n) return "";
        return resultString;
    }
};
