class Solution {
public:
    vector<vector<int>> threeSum(const vector<int>& nums) {
        if(nums.size() < 3) return {};
        std::vector<vector<int>> resultVector;

        std::vector<int> numsCopy(nums.begin(), nums.end());
        std::sort(numsCopy.begin(), numsCopy.end());

        for(size_t i = 0; i < nums.size() - 2; i++){
            if(numsCopy[i] > 0) break;
            if(i > 0 && numsCopy[i] == numsCopy[i-1]) continue;
            size_t left = i + 1;
            size_t right = nums.size() - 1;
            while(left < right){
                int sum = numsCopy[i] + numsCopy[left] + numsCopy[right];
                if(sum == 0){
                    resultVector.push_back({numsCopy[i], numsCopy[left], numsCopy[right]});

                    while(left < right && numsCopy[left] == numsCopy[left+1]) left++;

                    while(left < right && numsCopy[right] == numsCopy[right-1]) right--;

                    left++;
                    right--;
                } else if(sum > 0){
                    right--;
                } else {
                    left++;
                }
            }
        }
        return resultVector;
    }
};
