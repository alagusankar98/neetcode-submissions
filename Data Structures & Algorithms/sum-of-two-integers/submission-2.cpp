class Solution {
public:
    int getSum(int a, int b) {
        bool carryBit = false;
        int sum = 0;
        int count = 0;
        for(size_t i = 0; i < 32; i++){
            bool val1 = a & 1;
            bool val2 = b & 1;
            int sumBit = val1 ^ val2 ^ carryBit;
            carryBit = (val1 & val2) | (val2 & carryBit) | (val1 & carryBit);
            sum = (sumBit << i) | sum;
            a = a >> 1;
            b = b >> 1;
        }
        return sum;
    }
};
