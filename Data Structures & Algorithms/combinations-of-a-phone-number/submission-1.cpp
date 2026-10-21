class Solution {
public:
    std::vector<std::string> letterCombinations(std::string_view digits) {
        std::vector<std::string> resultVector;
        static constexpr std::array<std::string, 8> digitMap = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    for(const char c : digits){
        if(resultVector.empty()) resultVector.push_back("");
        std::vector<std::string> tempVector;
        tempVector.reserve(resultVector.size() * digitMap[c - '0' - 2].size());
        for(const auto& str : resultVector){
            for(const auto& val : digitMap[c - '0' - 2]){
                tempVector.emplace_back(str).push_back(val);
            }
        }
            resultVector = std::move(tempVector);
        }
        return resultVector;
    }
};
