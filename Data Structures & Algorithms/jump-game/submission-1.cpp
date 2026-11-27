class Solution {
public:
    bool canJump(const std::vector<int>& nums) {
        size_t farthestIndex = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if(i > farthestIndex) return false;
            farthestIndex = std::max(i + nums[i], farthestIndex);
            if((farthestIndex + 1) >= nums.size()) return true;
        }
        return true;
    }
};
