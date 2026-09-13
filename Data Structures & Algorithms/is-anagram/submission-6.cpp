class Solution {
public:
    bool isAnagram(std::string_view s, std::string_view t) {
        if(s.size() != t.size()) return false;

        std::array<int, 26> charCount = {0};

        for(size_t i = 0; i < s.size(); i++){
            charCount[s[i] - 'a']++;
            charCount[t[i] - 'a']--;
        }

        return std::ranges::all_of(charCount.begin(), charCount.end(), [](int count){
            return count == 0;
        });
    }
};
