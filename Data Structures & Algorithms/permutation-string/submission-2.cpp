class Solution {
public:
    bool checkInclusion(std::string_view s1, std::string_view s2) {
        if(s1.size() > s2.size()) return false;
        std::array<int, 26> s1Count{}, s2Count{};
        for(size_t i = 0; i < s1.size(); i++){
            s1Count[static_cast<unsigned char>(s1[i]) - 'a']++;
            s2Count[static_cast<unsigned char>(s2[i]) - 'a']++;
        }

        uint32_t matchBits = 0;
        for(size_t i = 0; i < 26; i++){
            if(s1Count[i] == s2Count[i]){
                matchBits = matchBits | (1 << i);
            }
        }

        size_t left = 0;
        
        for(size_t right = s1.size(); right < s2.size(); right++){
            
            // Check if all 26 characters match
            if((matchBits & 0x03FFFFFF) == 0x03FFFFFF) return true;

            // Let go of left character
            int leftCharIndex = static_cast<unsigned char>(s2[left]) - 'a';
            s2Count[leftCharIndex]--;
            if(s1Count[leftCharIndex] == s2Count[leftCharIndex]){
                matchBits = matchBits | (1 << leftCharIndex);
            } else {
                matchBits = matchBits & (~(1 << leftCharIndex));
            }
            left++;

            // Ingest right character
            int rightCharIndex = static_cast<unsigned char>(s2[right]) - 'a';
            s2Count[rightCharIndex]++;
            if(s1Count[rightCharIndex] == s2Count[rightCharIndex]){
                matchBits = matchBits | (1 << rightCharIndex);
            } else {
                matchBits = matchBits & (~(1 << rightCharIndex));
            }
        }
        return ((matchBits & 0x03FFFFFF) == 0x03FFFFFF);
    }
};
