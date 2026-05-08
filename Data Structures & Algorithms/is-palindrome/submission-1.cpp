class Solution {
public:
    bool isPalindrome(const string& s) {
        size_t right = s.size() - 1;
        size_t left = 0;

        while(left < right){
            if(!std::isalnum(s[left])) {left++; continue;}
            if(!std::isalnum(s[right])) {right--; continue;}
            if(std::tolower(s[left]) != std::tolower(s[right])) return false;
            left++;
            right--;
        }
        return true;
    }
};
