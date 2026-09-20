class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int carCount = 0;
        std::vector<std::pair<int, double>> hoursRemaining(position.size());
        for(size_t i = 0; i < position.size(); i++){
            hoursRemaining[i].second = (target - position[i]) / static_cast<double>(speed[i]);
            hoursRemaining[i].first = position[i];
        }

        // Sort based on position (from small to large)
        std::sort(hoursRemaining.begin(), hoursRemaining.end(), std::greater<std::pair<int, double>>());

        double prevBottleNeckTime = std::numeric_limits<double>::min();

    for(const auto& [_, currentBottleNeckTime] : hoursRemaining){
        if(currentBottleNeckTime > prevBottleNeckTime){
            prevBottleNeckTime = currentBottleNeckTime;
            carCount++;
        }
    }
        return carCount;
    }
};
