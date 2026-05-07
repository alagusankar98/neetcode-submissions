class Solution {
public:
    vector<int> topKFrequent(const vector<int>& nums, int k) {
        if (nums.empty()) return {};
        std::unordered_map<int, uint16_t> frequencyMap;

        frequencyMap.reserve(nums.size());
        for(auto const num : nums){
            frequencyMap[num]++;
        }

        std::vector<std::vector<int>> bucket((nums.size() + 1));

        for(auto const& [key, value] : frequencyMap){
            bucket[value].push_back(key);
        }

        std::vector<int> repeatedElements;
        repeatedElements.reserve(k);
        for(int i = bucket.size() - 1; i > 0; i--){
            for(const auto val : bucket[i]){
                repeatedElements.push_back(val);
                if(repeatedElements.size() == static_cast<int>(k)) return repeatedElements;
            }
        }

        return repeatedElements;
    }
};
