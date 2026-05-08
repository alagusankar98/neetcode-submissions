class Solution {
public:
    bool isPalindrome(const string& s) {
        if(s.empty()) return true;
        size_t right = s.size() - 1;
        size_t left = 0;

        while(left < right){
            auto leftChar = static_cast<unsigned char>(s[left]);
            auto rightChar = static_cast<unsigned char>(s[right]);
            if(!std::isalnum(leftChar)) {left++; continue;}
            if(!std::isalnum(rightChar)) {right--; continue;}
            if(std::tolower(leftChar) != std::tolower(rightChar)) return false;
            left++;
            right--;
        }
        return true;
    }
};
