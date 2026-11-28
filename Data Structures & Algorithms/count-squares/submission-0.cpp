class CountSquares {
private:
    std::unordered_map<int, std::unordered_map<int, int>> frequencyMap;
public:
    CountSquares() {
        
    }
    
    void add(const std::vector<int>& point) {
        frequencyMap[point[0]][point[1]]++;
    }
    
    int count(const std::vector<int>& point) {
        int x1 = point[0];
        int y1 = point[1];

        auto x1It = frequencyMap.find(x1);
        if(x1It == frequencyMap.end()) return 0;

        int squareCount = 0;

        for(const auto& [y2, y2Count] : x1It->second) {
            int side = std::abs(y2 - y1);
            if(side == 0) continue;

            squareCount += countHelper(x1 + side, y1, y2, y2Count) + countHelper(x1 - side, y1, y2, y2Count);
        }
        return squareCount;
    }

    int countHelper(int sideX, int yLo, int yHi, int yCount) {
        auto sideXIt = frequencyMap.find(sideX);
        int count = 0;
        if(sideXIt != frequencyMap.end()) {
            auto yLoIt = sideXIt->second.find(yLo);
            auto yHiIt = sideXIt->second.find(yHi);
            if(yLoIt != sideXIt->second.end() && yHiIt != sideXIt->second.end()) {
                count += (yLoIt->second * yHiIt->second * yCount);
            }
        }
        return count;
    }
};
