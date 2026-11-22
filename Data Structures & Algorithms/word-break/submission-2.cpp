class Solution {
public:
    bool wordBreak(std::string_view s, const std::vector<std::string>& wordDict) {
        std::unordered_set<std::string_view> wordSet;
        wordSet.reserve(wordDict.size());
        int maxLen = 0;
        for(const auto& str : wordDict) {
            wordSet.insert(str);
            maxLen = std::max(maxLen, static_cast<int>(str.size()));
        }

        const int n = static_cast<int>(s.size());
        std::vector<bool> dp(n + 1, false);
        dp[n] = true;

        for(int i = n - 1; i >= 0; i--) {
            if(!dp[i + 1]) continue;
            for(int wordLength = std::min(i + 1, maxLen); wordLength > 0; wordLength--) {
                if(!dp[i + 1 - wordLength] && wordSet.contains(s.substr(i + 1 - wordLength, wordLength))){
                    dp[i + 1 - wordLength] = true;
                }
            }
        }

        return dp[0];
    }
};
