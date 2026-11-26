class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxSum = std::numeric_limits<int>::min();
        for(size_t i = 0; i < nums.size(); i++) {
            if(sum < 0 && (nums[i] > sum)) {
                sum = 0;
            }
            sum += nums[i];
            maxSum = std::max(sum, maxSum);
        }
        return maxSum;
    }
};
