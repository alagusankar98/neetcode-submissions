class Solution {
public:
    int jump(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        int currentFarthestIdx = 0;
        int numberOfJumps = 0;
        int consumeIdx = 0;

        while(currentFarthestIdx < (n - 1)) { // Current Group cannot reach final node

            int nextFarthestIdx = -1;
            for(; consumeIdx <= currentFarthestIdx; consumeIdx++) {
                // Consume all nodes in current group to find next group
                nextFarthestIdx = std::max(nextFarthestIdx, (consumeIdx + nums[consumeIdx]));
            }

            if(currentFarthestIdx == nextFarthestIdx) return -1; // New group same as old group

            currentFarthestIdx = nextFarthestIdx;
            numberOfJumps++;
        }

        return numberOfJumps;
    }
};
