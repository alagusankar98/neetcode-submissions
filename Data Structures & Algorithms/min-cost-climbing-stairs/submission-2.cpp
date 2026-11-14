class Solution {
public:
    int dfs(const std::vector<int>& cost, size_t i){
        if(i >= cost.size()) return 0;


        return cost[i] + min(dfs(cost, i+1), dfs(cost, i+2));
    }
    int minCostClimbingStairs(const std::vector<int>& cost) {
        const int n = static_cast<int>(cost.size());
        int prev2 = cost[0], prev1 = cost[1];
        for(int i = 2; i < n; i++){
            int temp = cost[i] + std::min(prev2, prev1);
            prev2 = prev1;
            prev1 = temp;
        }
        return std::min(prev2, prev1);
    }
};
