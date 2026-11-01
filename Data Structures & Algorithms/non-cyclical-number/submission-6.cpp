class Solution {
public:
    uint64_t happyNumber(int n){
        uint64_t result = 0;
        while(n > 0){
            int remainder = n % 10;
            n = n / 10;
            result += static_cast<uint64_t>(remainder * remainder);
        }
        return result;
    }
    bool isHappy(int n) {
        uint64_t slow = static_cast<uint64_t>(n);
        uint64_t fast = slow;
        do {
            slow = happyNumber(slow);
            fast = happyNumber(happyNumber(fast));
            if(slow == 1 || fast == 1) return true;
        } while(slow != fast);

        return false;
    }
};
