class Solution {
public:
    bool isMatchHelper(std::string_view inStr, std::string_view pattern, int i, int j, const int n1, const int n2, std::vector<std::vector<uint8_t>>& dp) {
        if(j == n2) return (i == n1);

        if(dp[i][j] != std::numeric_limits<uint8_t>::max()) return dp[i][j];

        const bool firstMatch = ((i < n1) && ((inStr[i] == pattern[j]) || (pattern[j] == '.')));

        bool resultFlag = false;
        if(((j + 1) < n2) && (pattern[j + 1] == '*')) {
            resultFlag = (isMatchHelper(inStr, pattern, i, j + 2, n1, n2, dp) || (firstMatch && isMatchHelper(inStr, pattern, i + 1, j, n1, n2, dp)));
        } else {
            resultFlag = (firstMatch && isMatchHelper(inStr, pattern, i + 1, j + 1, n1, n2, dp));
        }

        return dp[i][j] = resultFlag;
    }
    bool isMatch(std::string_view s, std::string_view p) {
        const int n1 = static_cast<int>(s.size());
        const int n2 = static_cast<int>(p.size());

        std::vector<std::vector<uint8_t>> dp(n1 + 1, std::vector<uint8_t>(n2, std::numeric_limits<uint8_t>::max()));

        return isMatchHelper(s, p, 0, 0, n1, n2, dp);
    }
};
