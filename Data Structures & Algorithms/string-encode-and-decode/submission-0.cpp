#include <cstring>
class Solution {
public:
    uint8_t offset = 1;

    string encode(const vector<string>& strs) {
        std::string encodedResultString;
        for(const auto& str : strs){
            std::string encodedString = std::to_string(str.size()) + "#";
            for(const char c : str){
                encodedString += (char)(c + offset);
            }
            encodedResultString += encodedString;
        }
        return encodedResultString;
    }

    size_t stringToNum(const std::string& str){
        // Expects the str to only have character set '0' to '9'
        size_t length = 0;
        for(const char c : str){
            length = length*10 + (c - '0');
        }
        return length;
    }

    vector<string> decode(const string& s) {
        std::vector<std::string> decodedStringVector;
        std::string decodedString;
        for(size_t i = 0; i < s.size();){
            // Gather Length
            std::string tempString;
            while((char)s[i] != (char)'#'){
                tempString += s[i];
                i++;
            }
            i++; // Skip '#' character

            // Convert length in string to number
            auto length = i + stringToNum(tempString);
            tempString = "";

            for(; i < length; i++){
                tempString += (char)(s[i] - offset);
            }
            decodedStringVector.push_back(tempString);
        }
        return decodedStringVector;
    }
};
