class Solution {
public:
    int64_t countHours(const std::vector<int>& piles, int k){
        int64_t count = 0;
        for(const int pile : piles){
            count += (pile / k) + ((pile % k == 0) ? 0 : 1);
        }
        return count;
    }
    int minEatingSpeed(const std::vector<int>& piles, int h) {
        int left = 1; // Cannot eat 0 bananas
        int right = *(std::max_element(piles.begin(), piles.end())); // Worse case for right
        int minH = std::numeric_limits<int>::max();

        while(left <= right){
            int mid = left + (right - left) / 2;
            int64_t currentHours = countHours(piles, mid);

            if(currentHours <= h){
                minH = std::min(minH, mid);
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return minH;
    }
};
