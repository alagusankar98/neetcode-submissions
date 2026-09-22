class Solution {
public:
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        if(piles.empty()) return 0;
        int left = 1; // Cannot eat 0 bananas
        int right = *(std::max_element(piles.begin(), piles.end())); // Worse case for right
        // int minH = std::numeric_limits<int>::max();

        while(left <= right){
            int mid = left + (right - left) / 2;
            int64_t currentHours = 0;

            for(const int pile : piles){
                currentHours += ((pile + mid - 1) / mid);
            }

            if(currentHours <= h){
                // minH = std::min(minH, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};
