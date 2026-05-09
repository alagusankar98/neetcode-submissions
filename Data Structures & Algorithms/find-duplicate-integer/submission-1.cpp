class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(size_t i = 0; i < nums.size(); i++){
            int numToCheck = std::abs(nums[i]);
            if(nums[numToCheck - 1] < 0) return numToCheck;

            nums[numToCheck - 1] *= -1;
        }
        return -1; // Should not reach
    }
};
