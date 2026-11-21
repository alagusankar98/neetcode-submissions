class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentMinProduct = 1;
        int currentMaxProduct = 1;
        int maxResult = std::numeric_limits<int>::min();

        for(const int num : nums) {
            if(num < 0) std::swap(currentMinProduct, currentMaxProduct);
            currentMaxProduct = std::max(num, currentMaxProduct * num);
            currentMinProduct = std::min(num, currentMinProduct * num);
            maxResult = std::max(maxResult, currentMaxProduct);
        }
        return maxResult;
    }
};
