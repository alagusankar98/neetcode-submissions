class Solution {
public:
    int binarySearch(const std::vector<int>& nums, int target) {
        const int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] >= target){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int lengthOfLIS(const std::vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        std::vector<int> subset;
        subset.reserve(n);

        for(const int num : nums) {
            if(int targetIdx = binarySearch(subset, num); targetIdx < static_cast<int>(subset.size())){
                subset[targetIdx] = num;
            } else {
                subset.push_back(num);
            }
        }

        return static_cast<int>(subset.size());
    }
};
