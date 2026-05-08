class Solution {
public:
    int maxArea(const vector<int>& heights) {
        if(heights.size() < 2) return 0; // Can't have a container without two walls

        size_t left = 0;
        size_t right = heights.size() - 1;
        int maxArea = 0;

        while(left < right){ // [0, 7], [1, 7]
            int width = static_cast<int>(right) - static_cast<int>(left); // 7, 6
            maxArea = std::max((width * std::min(heights[left], heights[right])), maxArea); // (max(7 * min(1,6), 0) = 6), (max(6 * min(7,6), 6) = 36)
            
            if(heights[left] < heights[right]){ // (1 < 7)
                left++; // 1
            } else {
                right--; // 
            }
        }

        return maxArea;
    }
};
