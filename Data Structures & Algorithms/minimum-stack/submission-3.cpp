#include <cassert>

struct minData{
    int val;
    int min;
};

class MinStack {
private:
    std::vector<minData> stackVar;
public:
    MinStack() {
        stackVar.reserve(30000);
    }
    
    void push(int val) {
        // Check if current val is less than already present min element
        int minVal = (stackVar.empty()) ? val : std::min(val, stackVar.back().min);
        stackVar.push_back({val, minVal});

    }
    
    void pop() {
        assert(!stackVar.empty());
    
        stackVar.pop_back();
    }
    
    int top() {
        assert(!stackVar.empty());

        return stackVar.back().val;
    }
    
    int getMin() {
        assert(!stackVar.empty());

        return stackVar.back().min;
    }
};
