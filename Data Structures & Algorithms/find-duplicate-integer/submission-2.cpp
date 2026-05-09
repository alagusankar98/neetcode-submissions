class Solution {
public:
    int idx(const vector<int>& nums, int i){
        return nums[i - 1];
    }
    int findDuplicate(vector<int>& nums) {
        if(nums.size() < 2) return -1; // Should not reach

        int fast = nums[0]; // 1, 
        int slow = nums[0]; // 1, 

        while(fast < nums.size() && nums[fast] < nums.size()){ // ( 1 < 5 && 2 < 5), (3 < 5 && 4 < 5), (4 < 5 && 4 < 5)
            slow = nums[slow]; // 2, 3, 4
            fast = nums[nums[fast]]; // 3, 4, 4
            if(slow == fast) break;
        }

        int duplicateIndex = nums[0];

        while(duplicateIndex < nums.size() && slow < nums.size()){
            if(duplicateIndex == slow) return slow;
            duplicateIndex = nums[duplicateIndex];
            slow = nums[slow];
        }

        return -1;
    }
};
