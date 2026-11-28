class CountSquares {
private:
    std::unordered_map<int, std::unordered_map<int, int>> frequencyMap;
public: 
    void add(const std::vector<int>& point) {
        frequencyMap[point[0]][point[1]]++;
    }
    
    int count(const std::vector<int>& point) const {
        int x1 = point[0];
        int y1 = point[1];

        auto x1It = frequencyMap.find(x1);
        if(x1It == frequencyMap.end()) return 0;

        int squareCount = 0;

        for(const auto& [y2, y2Count] : x1It->second) {
            int side = std::abs(y2 - y1);
            if(side == 0) continue;

            squareCount += countHelper(x1 + side, y2, y1, y2Count) + countHelper(x1 - side, y2, y1, y2Count);
        }
        return squareCount;
    }

    int countHelper(int sideX, int y2, int y1, int yCount) const {
        auto sideXIt = frequencyMap.find(sideX);
        int count = 0;
        if(sideXIt != frequencyMap.end()) {
            auto y2It = sideXIt->second.find(y2);
            auto y1It = sideXIt->second.find(y1);
            if(y2It != sideXIt->second.end() && y1It != sideXIt->second.end()) {
                count += (y2It->second * y1It->second * yCount);
            }
        }
        return count;
    }
};
