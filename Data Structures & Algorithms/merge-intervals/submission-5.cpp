class Solution {
private:
public:
    std::vector<std::vector<int>> merge(const std::vector<std::vector<int>>& intervals) {
        if(intervals.empty()) return {};

        std::vector<std::pair<int, int>> intervalsCopy;
        intervalsCopy.reserve(intervals.size());
        for(auto const& interval : intervals) {
            intervalsCopy.emplace_back(interval[0], interval[1]);
        }

        std::sort(intervalsCopy.begin(), intervalsCopy.end());

        std::pair<int, int> reference = intervalsCopy[0];
        std::vector<std::vector<int>> resultVector;
        resultVector.reserve(intervalsCopy.size());

        for(std::size_t i = 1; i < intervalsCopy.size(); i++){
            if(intervalsCopy[i].first <= reference.second){
                reference.second = std::max(reference.second, intervalsCopy[i].second);
            } else {
                resultVector.push_back({reference.first, reference.second});
                reference = intervalsCopy[i];
            }
        }
        resultVector.push_back({reference.first, reference.second});
        return resultVector;
    }
};
