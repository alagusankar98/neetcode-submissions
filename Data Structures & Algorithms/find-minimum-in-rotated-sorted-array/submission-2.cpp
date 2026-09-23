class Solution {
public:
    int findMin(const std::vector<int> &nums) {
        const int n = static_cast<int>(nums.size());
        int left = 0;
        int right = n - 1;

        while(left <= right){
            if(nums[left] <= nums[right]){
                // we have a sorted segment, left must be the lowest element
                return nums[left];
            }
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right]){
                // Start of segment greater than end. Means minimum element is here somewhere
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return -1;
    }
};
