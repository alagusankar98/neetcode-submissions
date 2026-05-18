class Solution {
public:
    int maxProfit(const vector<int>& prices) {
        int profit = 0;
        int minLeft = INT_MAX;
        for(const int price : prices){
            profit = std::max(profit, price - minLeft);
            minLeft = std::min(minLeft, price);
        }
        return profit;
    }
};
