class Solution {
public:
    struct ArrayHasher {
        std::size_t operator()(const std::array<uint8_t, 26>& inputArray) const{
            std::size_t hashValue = 17; // To have different hash for [0,0,5] vs [5]
            for(const auto val : inputArray){
                hashValue = hashValue * 31 + val;
            }
            return hashValue;
        }
    };
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        std::unordered_map<std::array<uint8_t, 26>, std::vector<std::string>, ArrayHasher> anagramMap;
        anagramMap.reserve(strs.size());
        std::vector<std::vector<std::string>> anagramVector;
        anagramVector.reserve(strs.size());

        for(const auto& str : strs){
            std::array<uint8_t, 26> charCount{0};
            for(const auto c : str){
                charCount[c - 'a']++;
            }
            
            anagramMap[charCount].push_back(str);
        }

        for(auto& [_, strVector] : anagramMap){
            anagramVector.push_back(std::move(strVector));
        }
        return anagramVector;
    }
};
