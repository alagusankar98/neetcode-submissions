class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, const int target) {
        std::unordered_map<int, int> targetSum;
        
        targetSum.reserve(nums.size());

        for(size_t i = 0; i < nums.size(); i++){
            if(auto it = targetSum.find(nums[i]); it != targetSum.end()){
                return {static_cast<int>(it->second), static_cast<int>(i)};
            }

            targetSum.insert({target - nums[i], static_cast<int>(i)});
        }
        return {};
    }
};
