class Solution {
public:
    int trap(const vector<int>& height) {
        if(height.empty()) return 0;

        size_t left = 0;
        size_t right = height.size() - 1;
        int leftMax = height[left]; // 0
        int rightMax = height[right]; // 1
        int totalWater = 0;

        while(left < right){ // [0 < 10]
            if(leftMax < rightMax){ // [ 0 <= 1],
                left++;
                
                if(height[left] >= leftMax){
                    leftMax = height[left];
                } else {
                    totalWater += std::min(leftMax, rightMax) - height[left];
                }  
            } else {
                right--;

                if(height[right] >= rightMax){
                    rightMax = height[right];
                } else {
                    totalWater += std::min(leftMax, rightMax) - height[right];
                }  
            }
        }
        return totalWater;
    }
};
