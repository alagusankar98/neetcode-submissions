class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        std::vector<int> prefixVector(nums.size());
        std::vector<int> suffixVector(nums.size());
        std::vector<int> productVector(nums.size());
        int32_t totalProduct = 1;
        auto n = nums.size();
        for(size_t i = 0; i < n; i++){
            prefixVector[i] = totalProduct;
            totalProduct *= nums[i];
        }

        totalProduct = 1;
        for(int i = n - 1; i >= 0; i--){
            suffixVector[i] = totalProduct;
            totalProduct *= nums[i];
        }

        for(size_t i = 0; i < n; i++){
            productVector[i] = prefixVector[i] * suffixVector[i];
        }
        return productVector;
    }
};
