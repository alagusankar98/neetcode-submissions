#include <cassert>
class Solution {
public:
    int findTargetSumWays(const std::vector<int>& nums, int target) {
        int absSum = 0;
        for(const int num : nums) {
            assert(num >= 0);
            absSum += num;
        }

        if(std::abs(target) > absSum) return 0;

        int positiveSum = absSum + target;
        if(positiveSum & 1) return 0;

        const int P = (positiveSum / 2);
        const int n = static_cast<int>(nums.size());
        std::vector<int> current(P + 1, 0);
        current[0] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int remSum = P; remSum >= nums[i]; remSum--) {
                current[remSum] += current[remSum - nums[i]];
            }
        }
        return current[P];
    }
};
