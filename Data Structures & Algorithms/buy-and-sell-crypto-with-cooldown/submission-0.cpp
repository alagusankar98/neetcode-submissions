class Solution {
public:
    int maxProfit(vector<int>& prices) {
        const int n = static_cast<int>(prices.size());
        int buyTomorrow = 0;
        int buyDayAfterTomorrow = 0;
        int sellTomorrow = 0;

        for(int i = n - 1; i >= 0; i--) {
            int buyToday = std::max(buyTomorrow, sellTomorrow - prices[i]);
            int sellToday = std::max(sellTomorrow, buyDayAfterTomorrow + prices[i]);
            buyDayAfterTomorrow = buyTomorrow;
            buyTomorrow = buyToday;
            sellTomorrow = sellToday;
        }

        return buyTomorrow;
    }
};
