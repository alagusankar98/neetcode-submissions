class Solution {
public:
    int characterReplacement(std::string_view s, int k) {
        if(s.empty()) return 0;
        int left = 0;
        char lastValidChar = s[0];
        int maxFrequency = 0;
        int longestCount = 0;
        std::array<int, 26> seen{};
        for(int right = 0; right < s.size(); right++){
            size_t charIdx = static_cast<unsigned char>(s[right]) - 'A';

            seen[charIdx]++;
            maxFrequency = std::max(maxFrequency, seen[charIdx]);

            if((right - left + 1) - maxFrequency > k){
                seen[s[left] - 'A']--;
                left++;
            }

            longestCount = std::max(longestCount, (right - left + 1));
        }
        return longestCount;
    }
};
