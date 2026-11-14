class Solution {
public:
    int dfs(const std::vector<int>& cost, size_t i){
        if(i >= cost.size()) return 0;


        return cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
    }
    int minCostClimbingStairs(const std::vector<int>& cost) {
        const int n = static_cast<int>(cost.size());
        std::vector<int> dp(n, 0);
        dp[0] = cost[0]; dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + std::min(dp[i-1], dp[i-2]);
        }
        return std::min(dp[n-1], dp[n-2]);
    }
};
