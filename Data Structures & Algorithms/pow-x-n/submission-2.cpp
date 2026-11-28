class Solution {
public:
    double myPow(double x, int n) {
        if(x == 0) return 0;
        if(n == 0 || x == 1) return 1;
        long cycles = static_cast<long>(n);
        bool isNegative = (cycles < 0);
        cycles = std::abs(cycles);
        double result = 1;

        while(cycles > 0) {
            if(cycles & 1) {
                result *= x;
            }
            x *= x;
            cycles = cycles / 2;
        }

        return isNegative ? (1 / result) : result;
    }
};
