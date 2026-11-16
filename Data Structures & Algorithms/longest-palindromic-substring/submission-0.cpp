



class Solution {
public:
    std::string longestPalindrome(std::string_view s) {
        const int n = static_cast<int>(s.size());
        int start = 0;
        int length = 0;
        std::vector<std::vector<uint8_t>> dp(n, std::vector<uint8_t>(n, 0));
        
        bool previousAny = false;
        for(int difference = 0; difference < n; difference++){
            bool currentAny = false;
            for(int i = 0; (i + difference) < n; i++){
                int j = i + difference;
                dp[i][j] = (s[i] == s[j]) && ((difference < 2) || dp[i+1][j-1]);
                if(dp[i][j]){
                    currentAny = true;
                    if(length < (j - i + 1)){
                        length = (j - i + 1);
                        start = i;
                    }
                }
            }
            if(!currentAny && !previousAny) break; // Stop if two consecutive loops did not have palindromes
            previousAny = currentAny;
        }

        return std::string(s.data() + start, length);
    }
};