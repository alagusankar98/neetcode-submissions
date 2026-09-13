class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> characterMap;
        for(const char c : s){
            characterMap[c]++;
        }
        for(const char c : t){
            if(--characterMap[c] < 0) return false;
        }
        for(const auto& [_, value] : characterMap){
            if(value != 0) return false;
        }
        return true;
    }
};
