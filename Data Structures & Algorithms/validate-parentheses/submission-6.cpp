class Solution {
public:
    bool isValid(std::string_view s) {
        std::stack<char, std::vector<char>> bracketStack;
        for(const char c : s){
            switch(c) {
                case '(' : bracketStack.push(')'); break;
                case '[' : bracketStack.push(']'); break;
                case '{' : bracketStack.push('}'); break;
                case ')':
                case '}':
                case ']':
                    if(bracketStack.empty() || bracketStack.top() != c) return false;
                    bracketStack.pop();
                    break;
                default:
                    return false;
            }
        }
        return bracketStack.empty();
    }
};
