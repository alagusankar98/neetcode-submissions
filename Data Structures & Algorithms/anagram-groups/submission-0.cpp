class Solution {
public:
    vector<vector<string>> groupAnagrams(const vector<string>& strs) {
        std::map<std::array<uint16_t, 26>, std::vector<std::string>> anagramMap;
        // anagramMap.reserve(strs.size());
        std::vector<std::vector<std::string>> anagramVector;

        for(const auto& str : strs){
            std::array<uint16_t, 26> charCount{0};
            for(const auto& c : str){
                charCount[c - 'a']++;
            }
            if(auto it = anagramMap.find(charCount); it != anagramMap.end()){
                it->second.push_back(str);
            } else {
                anagramMap.insert({charCount, {str}});
            }
        }

        for(const auto& [_, strVector] : anagramMap){
            anagramVector.push_back(strVector);
        }
        return anagramVector;
    }
};
