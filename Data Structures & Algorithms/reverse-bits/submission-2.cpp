class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        uint8_t count = 0;
        while(n > 0){
            result = result << 1;
            result = result | (n & 1);
            n = n >> 1;
            count++;
        }
        return result << (32 - count);
    }
};
