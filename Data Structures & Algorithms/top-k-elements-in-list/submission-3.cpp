class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        if (nums.empty()) return {};
        std::unordered_map<int, uint16_t> frequencyMap;

        for(auto const num : nums){
            frequencyMap[num]++;
        }

        std::vector<std::vector<int>> bucket((nums.size() + 1));

        for(auto const& [key, value] : frequencyMap){
            bucket[value].push_back(key);
        }

        std::vector<int> repeatedElements;
        repeatedElements.reserve((frequencyMap.size()));
        for(int i = bucket.size() - 1; i > 0; i--){
            for(const auto val : bucket[i]){
                repeatedElements.push_back(val);
                k--;
            }
            if(k <= 0) break;
        }

        return repeatedElements;
    }
};
