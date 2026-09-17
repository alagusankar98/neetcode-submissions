class Solution {
public:
    int maxProfit(const std::vector<int>& prices) {
        int left = 0;
        int right = left;
        int n = std::ssize(prices);
        int maxDifference = 0;
        while(right < n){
            if(prices[right] < prices[left]){
                left = right;
            }
            maxDifference = std::max(maxDifference, (prices[right] - prices[left]));
            right++;
        }
        return maxDifference;
    }
};
