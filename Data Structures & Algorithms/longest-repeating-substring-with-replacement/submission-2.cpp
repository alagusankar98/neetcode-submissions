class Solution {
public:
    int characterReplacement(std::string_view s, int k) {
        int left = 0;
        int right = left;
        int n = std::ssize(s);
        int longestSequence = 0;
        int currentWindowPopularCount = 0;
        std::array<int, 26> seen{};
        while(right < n){
            unsigned char currentChar = static_cast<unsigned char>(s[right]);
            seen[currentChar - 'A']++;

            currentWindowPopularCount = std::max(currentWindowPopularCount, seen[currentChar - 'A']);
            if((right - left + 1) - currentWindowPopularCount > k){
                seen[s[left] - 'A']--;
                left++;
            }

            longestSequence = std::max(longestSequence, (right - left + 1));
            right++;
        }
        return longestSequence;
    }
};
