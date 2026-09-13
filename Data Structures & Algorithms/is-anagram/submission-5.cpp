class Solution {
public:
    bool isAnagram(std::string_view s, std::string_view t) {
        if(s.size() != t.size()) return false;

        std::array<int, 26> charCount = {0};

        for(size_t i = 0; i < s.size(); i++){
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }

        for(size_t i = 0; i < charCount.size(); i++){
            if(charCount[i] != 0) return false;
        }
        return true;
    }
};
