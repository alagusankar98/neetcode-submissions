class Solution {
public:
    bool isValid(std::string_view s) {
        std::unordered_map<unsigned char, unsigned char> brackets = {{')', '('},{'}', '{'},{']', '['}};

        std::stack<unsigned char> characters;
        for(const unsigned char c : s){
            if(auto it = brackets.find(c); it != brackets.end()){
                // Found a closing bracket
                if(characters.empty() || characters.top() != it->second ) return false;
                characters.pop();
            } else {
                characters.push(c);
            }
        }
        return characters.empty();
    }
};
