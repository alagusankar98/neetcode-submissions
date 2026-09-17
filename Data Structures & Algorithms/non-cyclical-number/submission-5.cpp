class Solution {
public:
    bool isHappy(int n) {
        while(n >= 10){
            int sum = 0;
            while(n > 0){
                uint8_t rem = n % 10;
                sum += (rem*rem);
                n = n / 10;
            }
            n = sum;
        }
        return (n == 1 || n == 7);
    }
};
