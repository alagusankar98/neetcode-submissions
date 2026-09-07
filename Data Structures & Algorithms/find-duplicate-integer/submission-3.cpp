class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.empty()) return -1;
        int slow = nums[0];
        int fast = nums[0];
        int n = static_cast<int>(nums.size());
        while(fast < n && nums[fast] < n){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(fast == slow) break;
        }

        fast = nums[0];
        while(fast < n && nums[fast] < n){
            if(slow == fast) return slow;
            slow = nums[slow];
            fast = nums[fast];
        }
        return -1;
    }
};
