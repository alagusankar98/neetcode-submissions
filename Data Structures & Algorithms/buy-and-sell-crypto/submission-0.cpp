class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        if(prices.empty()) return 0;
        int profit = 0;
        int minLeft = prices[0];
        for(size_t i = 1; i < prices.size(); i++){
            profit = std::max(profit, prices[i] - minLeft);
            minLeft = std::min(minLeft, prices[i]);
        }
        return profit;
    }
};
