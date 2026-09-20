class Solution {
public:
    std::vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        std::vector<size_t> temperatureStack;
        std::vector<int> resultVector(temperatures.size());

        for(size_t i = 0; i < temperatures.size(); i++){
            while(!temperatureStack.empty() && (temperatures[i] > temperatures[temperatureStack.back()])){
                auto idx = temperatureStack.back();
                resultVector[idx] = (i - idx);
                temperatureStack.pop_back();
            }
            temperatureStack.push_back(i);
        }
        return resultVector;
    }
};
