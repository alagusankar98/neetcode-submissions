class Solution {
public:
    bool hasDuplicate(const std::vector<int>& nums) {
    std::unordered_set<int> seenNumbers;
    seenNumbers.reserve(nums.size()); // To reduce bucket collision?
    for(const int num : nums){
        if (auto res = seenNumbers.insert(num); !res.second) return true;
    }
    return false;
}
};