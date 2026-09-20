class Solution {
public:
    vector<int> dailyTemperatures(const std::vector<int>& temperatures) {
        if(temperatures.empty()) return {};
        std::vector<size_t> temperatureStack;
        std::vector<int> resultVector(temperatures.size());

        for(size_t i = 0; i < temperatures.size(); i++){
            if(temperatureStack.empty() || temperatures[i] <= temperatures[temperatureStack.back()]){
                temperatureStack.push_back(i);
            } else {
                while(!temperatureStack.empty() && (temperatures[i] > temperatures[temperatureStack.back()])){
                    auto idx = temperatureStack.back();
                    resultVector[idx] = (i - idx);
                    temperatureStack.pop_back();
                }
                temperatureStack.push_back(i);
            }
        }
        return resultVector;
    }
};
