class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) {
        int longestCount = 0;
        std::array<int, 256> seen{-1};
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            unsigned char charIdx = static_cast<unsigned char>(s[i]);
            if(seen[charIdx] != 0){ // [(a, 0), [(b, 1)], [(a, 0), [(b, 2)]
                left = std::max(left, seen[charIdx]); // 2
            }
            seen[charIdx] = i + 1;
            longestCount = std::max(longestCount, (i - left + 1)); // max(0, 1), max(1, 2), max(2, )
        }
        return longestCount;
    }
};
