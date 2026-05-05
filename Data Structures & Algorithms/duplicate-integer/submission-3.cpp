class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_set<int> duplicateSet;
        duplicateSet.reserve(nums.size());

        for(const int num : nums){
            if(!(duplicateSet.insert(num).second)){
                return true;
            }
        }
        return false;
    }
};