class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        
        std::array<int, 26> letterCount{0};

        for(size_t i = 0; i < s.size(); i++){
            letterCount[s[i] - 'a']++;
            letterCount[t[i] - 'a']--;
        }

        for(const int count : letterCount){
            if(count != 0) return false;
        }
        return true;
    }
};
