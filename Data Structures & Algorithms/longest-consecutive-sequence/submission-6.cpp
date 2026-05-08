class Solution {
public:
    int longestConsecutive(const vector<int>& nums) {
        std::unordered_set<int> numSet;
        numSet.reserve(nums.size());
        for(const int num : nums){
            numSet.insert(num);
        }

        int longestSequence = 0;
        for(const int num : numSet){
            if(!numSet.contains(num - 1)){
                int consecutiveElements = 1;
                int nextNum = num + 1;
                while(numSet.contains(nextNum)){
                    consecutiveElements++;
                    nextNum++;
                }
                longestSequence = std::max(longestSequence,consecutiveElements);
            }
        }
        return longestSequence;
    }
};
