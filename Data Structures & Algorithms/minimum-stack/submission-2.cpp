#include <cassert>
struct DataMinVector{
    std::vector<int> val;
    std::vector<int> min;
};

class MinStack {
private:
    DataMinVector stackVar;
public:
    MinStack() {
        stackVar.val.reserve(30000);
        stackVar.min.reserve(30000);
    }
    
    void push(int val) {
        stackVar.val.push_back(val);
        // Check if current val is less than already present min element
        int minVal = (stackVar.min.empty()) ? val : std::min(val, stackVar.min.back());
        stackVar.min.push_back(minVal);

    }
    
    void pop() {
        if(stackVar.val.empty()) return;
        stackVar.val.pop_back();
        stackVar.min.pop_back();
    }
    
    int top() {
        assert(!stackVar.val.empty());

        return stackVar.val.back();
    }
    
    int getMin() {
        assert(!stackVar.val.empty());

        return stackVar.min.back();
    }
};
