class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        if(nums.size() < k) return {};
        int firstMax = std::numeric_limits<int>::min();
        int secondMax = std::numeric_limits<int>::min();

        std::deque<size_t> maxIdxQueue;
        
        // Initial run for first 'k' sized window
        // for(size_t i = 0; i < k; i++){
        //     // Consume ith index and pop small elements at back
        //     while(!maxIdxQueue.empty() && (nums[i] > nums[maxIdxQueue.back()])) maxIdxQueue.pop_back();
        //     maxIdxQueue.push_back(i);
        // }

        std::vector<int> maxWindowVector;
        maxWindowVector.reserve((nums.size() - k) + 1);

        for(size_t i = 0; i < nums.size(); i++){
            // Ingest right element
            while(!maxIdxQueue.empty() && (nums[i] >= nums[maxIdxQueue.back()])) maxIdxQueue.pop_back();
            maxIdxQueue.push_back(i);

            // Check if max element expired before access
            if(!maxIdxQueue.empty() && ((maxIdxQueue.front() + k) <= i)) maxIdxQueue.pop_front();

            // Push max element into vector
            if((i + 1) >= k) maxWindowVector.push_back(nums[maxIdxQueue.front()]);
        }
        return maxWindowVector;
    }
};
