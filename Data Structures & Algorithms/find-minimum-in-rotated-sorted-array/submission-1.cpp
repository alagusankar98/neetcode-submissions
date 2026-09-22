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
            int next = (mid + 1) % n;
            int prev = (mid + n - 1) % n;

            // Check if mid is the minimum element
            if((nums[mid] <= nums[prev]) && (nums[mid] <= nums[next])){
                return nums[mid];
            } else if (nums[mid] <= nums[right]){
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return -1;
    }
};
