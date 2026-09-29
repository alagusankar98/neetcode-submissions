class Solution {
public:
    double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        if(nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);
        const int n1 = static_cast<int>(nums1.size());
        const int n2 = static_cast<int>(nums2.size());
        const int totalHalf = (n1 + n2 + 1) / 2;

        int left = 0;
        int right = n1;

        while(left <= right){
            int sectionA = left + (right - left) / 2;
            int sectionB = totalHalf - sectionA;

            int maxLeftSectionA = (sectionA > 0) ? nums1[sectionA - 1] : std::numeric_limits<int>::min();
            int maxLeftSectionB = (sectionB > 0) ? nums2[sectionB - 1] : std::numeric_limits<int>::min();
            int minRightSectionA = (sectionA < n1) ? nums1[sectionA] : std::numeric_limits<int>::max();
            int minRightSectionB = (sectionB < n2) ? nums2[sectionB] : std::numeric_limits<int>::max();

            if(maxLeftSectionA <= minRightSectionB && maxLeftSectionB <= minRightSectionA){
                if((n1 + n2) % 2 == 0){
                    // Even length
                    return static_cast<double>(std::max(maxLeftSectionA, maxLeftSectionB) + std::min(minRightSectionA, minRightSectionB)) / 2;
                } else {
                    // Odd length
                    return std::max(maxLeftSectionA, maxLeftSectionB);
                }
            } else if(maxLeftSectionA > minRightSectionB){
                right = sectionA - 1;
            } else {
                left = sectionA + 1;
            }
        }
        return 0.0;
    }
};
