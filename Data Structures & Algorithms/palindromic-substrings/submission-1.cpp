class Solution {
public:
    int formPalindromeLength(std::string_view s, int left, int right) {
        const int n = static_cast<int>(s.size());
        while(left >= 0 && right < n && s[left] == s[right]){
            left--;
            right++;
        }
        return ((right - 1) - (left + 1) + 1);
    }
    int countSubstrings(std::string_view s) {
        const int n = static_cast<int>(s.size());

        int count = 0;
        for(int i = 0; i < n; i++){
            int oddLength = formPalindromeLength(s, i, i);
            int evenLength = formPalindromeLength(s, i, i+1);
            
            count += ((oddLength + evenLength + 1) / 2);
        }
        return count;
    }
};
