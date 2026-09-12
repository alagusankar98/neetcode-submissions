class Solution {
public:
    int reverse(int x) {
        bool isNegative = (x < 0);
        x = isNegative ? (-1 * x): x;
        int reverseNum = 0;

        while(x > 0){
            uint8_t digit = (x % 10);
            if(reverseNum > INT32_MAX/10) return 0;
            if(reverseNum == INT32_MAX/10){
                if((isNegative && digit > 8) || (~isNegative && digit > 7)) return 0;
            }
            reverseNum = reverseNum * 10 + digit;
            x = x / 10;
        }
        return isNegative ? (-1 * reverseNum) : reverseNum;
    }
};
