class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n, 1); // First row set to 1s
        for(int i = 1; i < m; i++){ // Process (m - 1) rows below
            for(int j = n - 1; j > 0; j--) {
                dp[j - 1] += dp[j];
            }
        }

        return dp[0];
    }
};
