class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        std::vector<int> numsCopy(nums.begin(), nums.end());
        std::sort(numsCopy.begin(), numsCopy.end());

        int longestSequence = 0;
        int consecutiveCount = 0;
        for(size_t i = 1; i < numsCopy.size(); i++){ // [2, 3, 4, 4, 5, 10, 20 ]
            if(numsCopy[i] == numsCopy[i - 1]) continue;

            if((numsCopy[i] - numsCopy[i - 1]) == 1){
                consecutiveCount++;
                if(consecutiveCount > longestSequence) longestSequence = consecutiveCount;
            } else {
                consecutiveCount = 0;
            }
        }
        return longestSequence + 1;
    }
};
