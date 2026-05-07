#include <cstring>
class Solution {
public:
    uint8_t offset = 1;

    string encode(const vector<string>& strs) {
        std::string encodedResultString;
        for(const auto& str : strs){
            encodedResultString += std::to_string(str.size()) + "#" + str;
        }
        return encodedResultString;
    }

    vector<string> decode(const string& s) {
        std::vector<std::string> decodedStringVector;
        std::string decodedString;
        size_t i = 0;
        while(i < s.size()){
            // Gather Length
            auto lengthPos = s.find("#", i); // (#, 0) -> 1, (#, 7) -> 8

            // Convert length in string to number
            auto length = std::stoi(s.substr(i, lengthPos - i)); // (0, 1) -> 5, (7, 8) -> 5
            i = lengthPos + 1; // 0 -> 2, 7 -> 9

            
            decodedStringVector.push_back(s.substr(i, length)); // 2, 5
            i += length; // 7
        }
        return decodedStringVector;
    }
};
