class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        int stringContains[26] = {0};
        
        for(const char c : s){
            stringContains[c - 'a']++;
        }

        for(const char c : t){
            stringContains[c - 'a']--;
        }

        for(size_t i = 0; i < 26; i++){
            if(stringContains[i] != 0) return false;
        }
        return true;
    }
};
