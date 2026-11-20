class Solution {
public:
    int coinChange(const std::vector<int>& coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for(size_t i = 0; i < coins.size(); i++){
            for(int fillAmount = coins[i]; fillAmount <= amount; fillAmount++){
                dp[fillAmount] = std::min(dp[fillAmount], dp[fillAmount - coins[i]] + 1);
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
    }
};
