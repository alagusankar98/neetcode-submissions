class Solution {
public:
    int lengthOfLongestSubstring(std::string_view s) {
        int longestCount = 0;
        std::unordered_map<unsigned char, size_t> seen;
        size_t left = 0;
        for(size_t i = 0; i < s.size(); i++){
            if(auto it = seen.find(s[i]); it != seen.end()){ // [(a, 0), [(b, 1)], [(a, 0), [(b, 2)]
                left = std::max(left, it->second + 1); // 2
                it->second = i; // 2
            } else {
                seen.insert({s[i], i}); // [(a, 0)], [(b, 1)], 
            }
            longestCount = std::max(longestCount, static_cast<int>(i - left + 1)); // max(0, 1), max(1, 2), max(2, )
        }
        return longestCount;
    }
};
