class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        if(numbers.empty() || numbers.size() == 1) return {};

        int index1 = 0;
        int index2 = numbers.size() - 1;

        while(index1 < index2){
            int sum = numbers[index1] + numbers[index2];

            if(sum == target) return {index1 + 1, index2 + 1};

            if(sum < target){
                index1++;
            } else {
                index2--;
            }
        }

        return {};
    }
};
