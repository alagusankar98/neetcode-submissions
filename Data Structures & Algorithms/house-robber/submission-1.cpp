class Solution {
public:
    int rob(vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int prev1 = 0, prev2 = 0;
        for(int i = 0; i < n; i++){
            int temp = std::max(prev2 + nums[i], prev1);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }
};
