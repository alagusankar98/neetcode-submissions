class Solution {
public:
    void letterGenerator(std::string_view s, const std::array<std::string_view, 8>& digitMap, std::vector<std::string>& resultVector, std::string& tempString, size_t i){
        if(i >= s.size()) return; // Used all in input string

        int charIdx = s[i] - '0' - 2;
        const std::string_view digitValues = digitMap[charIdx];
        for(size_t j = 0; j < digitValues.size(); j++){
            tempString.push_back(digitValues[j]);
            if(tempString.size() == s.size()) resultVector.push_back(tempString);
            letterGenerator(s, digitMap, resultVector, tempString, i + 1);
            tempString.pop_back();
        }
    }
    std::vector<std::string> letterCombinations(std::string_view digits) {
        std::vector<std::string> resultVector;
        static constexpr std::array<std::string_view, 8> digitMap = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        std::string tempString;
        letterGenerator(digits, digitMap, resultVector, tempString, 0);
        return resultVector;
    }
};
