class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) {
        int longestCount = 0;
        std::array<size_t, 256> seen{0};
        size_t left = 0;
        for(size_t i = 0; i < s.size(); i++){
            unsigned char charIdx = static_cast<unsigned char>(s[i]);
            if(seen[charIdx] != 0){ // [(a, 0), [(b, 1)], [(a, 0), [(b, 2)]
                left = std::max(left, seen[charIdx]); // 2
                seen[charIdx] = i + 1; // 2
            } else {
                seen[charIdx] = i + 1; // [(a, 0)], [(b, 1)], 
            }
            longestCount = std::max(longestCount, static_cast<int>(i - left + 1)); // max(0, 1), max(1, 2), max(2, )
        }
        return longestCount;
    }
};
