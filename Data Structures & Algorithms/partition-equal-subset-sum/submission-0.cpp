class Solution {
public:
    bool canPartition(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());

        int fullSum = 0;
        for(const int num : nums) {
            fullSum += num;
        }

        if(fullSum & 1) return false;

        int targetSum = fullSum / 2;

        std::vector<bool> dp(targetSum + 1, false);
        dp[0] = true;

        for(int i = n - 1; i >= 0; i--){
            for(int remSum = targetSum; remSum >= nums[i]; remSum--) {
                dp[remSum] = dp[remSum] || dp[remSum - nums[i]];
            }
            if(dp[targetSum]) return true;
        }

        return false;
    }
};
