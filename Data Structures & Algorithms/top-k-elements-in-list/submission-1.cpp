class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        std::unordered_map<int, uint16_t> valueToFrequencyMap;
        for(auto const num : nums){
            valueToFrequencyMap[num]++;
        }

        std::map<uint16_t, std::vector<int>> frequencyToValueMap;

        for(auto const& [key, value] : valueToFrequencyMap){
            frequencyToValueMap[value].push_back(key);
        }

        std::vector<int> resultVector;
        resultVector.reserve(k);
        for(auto it = frequencyToValueMap.rbegin(); it != frequencyToValueMap.rend() ;++it){
            for(auto const val : it->second){
                if(k > 0){
                    resultVector.push_back(val);
                    k--;
                }
            }
            if(k <= 0) break;
        }

        return resultVector;
    }
};
