class Solution {
public:
    vector<int> productExceptSelf(const vector<int>& nums) {
        std::vector<int> productVector(nums.size());
        int32_t totalProduct = 1;
        auto n = nums.size();
        for(size_t i = 0; i < n; i++){
            productVector[i] = totalProduct;
            totalProduct *= nums[i];
        }

        totalProduct = 1;
        for(size_t i = n; i-- > 0; ){
            productVector[i] *= totalProduct;
            totalProduct *= nums[i];
        }

        // for(size_t i = 0; i < n; i++){
        //     productVector[i] = prefixVector[i] * suffixVector[i];
        // }
        return productVector;
    }
};
