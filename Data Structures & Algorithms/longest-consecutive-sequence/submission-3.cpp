class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        std::unordered_set<int> numSet;
        numSet.reserve(nums.size());
        for(const auto num : nums){
            numSet.insert(num);
        }

        int longestSequence = 0;
        for(const auto num : numSet){
            if(numSet.count(num - 1) == 0){
                int consecutiveElements = 1;
                auto nextNum = num + 1;
                while(numSet.count(nextNum) != 0){
                    consecutiveElements++;
                    nextNum++;
                }
                if(consecutiveElements > longestSequence) longestSequence = consecutiveElements;
            }
        }
        return longestSequence;
    }
};
