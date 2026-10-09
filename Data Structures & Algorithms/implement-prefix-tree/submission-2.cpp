class TrieNode {
    public:
        std::array<TrieNode*, 26> next;
        bool isDone;
        TrieNode() :next({}), isDone(false) {}
};

class PrefixTree {
private:
    TrieNode* head_;
public:
    PrefixTree() {
        auto dummyNode = new TrieNode();
        head_ = dummyNode;
    }
    
    void insert(string word) {
        auto current = head_;
        for(const char c : word){
            int charIdx = c - 'a';
            if (!current->next[charIdx]) current->next[charIdx] = new TrieNode();
            current = current->next[charIdx];
        }
        current->isDone = true;
    }
    
    bool search(string word) {
        auto current = head_;
        for(const char c : word){
            int charIdx = c - 'a';
            if(!current->next[charIdx]) return false; // Character does not exist
            current = current->next[charIdx];
        }
        return current->isDone;
    }
    
    bool startsWith(string prefix) {
        auto current = head_;
        for(const char c : prefix){
            int charIdx = c - 'a';
            if(!current->next[charIdx]) return false; // Character does not exist
            current = current->next[charIdx];
        }
        return true;
    }

    ~PrefixTree() {
        std::stack<TrieNode*> trieStack;
        if(head_) trieStack.push(head_);
        while(!trieStack.empty()){
            auto nodeToDelete = trieStack.top(); trieStack.pop();

            for(auto& node : nodeToDelete->next){
                if(node) trieStack.push(node);
            }

            delete nodeToDelete;
        }
    }
};
