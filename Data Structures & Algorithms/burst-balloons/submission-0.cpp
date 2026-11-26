class Solution {
public:
    int maxCoins(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));

        for(int i = n - 1; i >= 0; i--) {
            int prevVal = (i > 0) ? nums[i - 1] : 1;
            for(int j = 0; j < n; j++) {
                int nextVal = (j + 1 < n) ? nums[j + 1] : 1;

                int count = 0;
                for(int k = j; k >= i; k--) {
                    count = std::max(count, (nums[k] * nextVal * prevVal) + ((k > 0) ? dp[i][k-1] : 0) + dp[k+1][j]);
                }
                dp[i][j] = count;
            }
        }
        return dp[0][n-1];
    }
};
