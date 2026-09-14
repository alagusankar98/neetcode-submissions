class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        std::unordered_map<int, int> frequencyMap;
        frequencyMap.reserve(nums.size()); // Worse case

        for(const int num : nums){
            frequencyMap[num]++;
        }

        using IntPair = std::pair<int, int>;
        std::priority_queue<IntPair, std::vector<IntPair>, std::greater<IntPair>> minQueue;
        for(const auto& [num, frequency] : frequencyMap){
            minQueue.push({frequency, num});
            if(minQueue.size() > k){
                minQueue.pop();
            }
        }

        std::vector<int> resultVector;
        resultVector.reserve(k); // Worse case
        while(!minQueue.empty()){
            auto [_, num] = minQueue.top();
            minQueue.pop();
            resultVector.push_back(num);
        }
        return resultVector;
    }
};
