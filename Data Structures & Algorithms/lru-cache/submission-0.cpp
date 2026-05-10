class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;

        Node() : next(nullptr), prev(nullptr) {}
        Node(int key, int val) : key(key), val(val), next(nullptr), prev(nullptr) {}
};

class LRUCache {
private:
    Node* dummyHead_;
    Node* dummyTail_;
    size_t size_;
    size_t capacity_;
    std::unordered_map<int, Node*> nodeMap_;
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
        size_ = 0;
        dummyHead_ = new Node();
        dummyTail_ = new Node();
        dummyHead_->next = dummyTail_;
        dummyTail_->prev = dummyHead_;
    }

    void insertAtTail(Node* newNode){
        // Insert node before dummy tail
        auto prevNode = dummyTail_->prev;
        newNode->prev = prevNode;
        newNode->next = dummyTail_;
        prevNode->next = newNode;
        dummyTail_->prev = newNode;
    }

    void removeNode(Node* nodeToRemove){
        // Remove node after dummy head
        nodeToRemove->prev->next = nodeToRemove->next;
        nodeToRemove->next->prev = nodeToRemove->prev;
    }

    
    int get(int key) {
        if(auto it = nodeMap_.find(key); it != nodeMap_.end()){
            Node* valueNode = it->second;

            if(valueNode != dummyTail_->prev){
                // Pop valueNode
                removeNode(valueNode);

                // Move valueNode to tail
                insertAtTail(valueNode);
            }

            return valueNode->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(auto it = nodeMap_.find(key); it != nodeMap_.end()){
            // Update existing node
            Node* valueNode = it->second;
            valueNode->val = value;

            // Pop and replace if node isn't already at MRU position
            if(valueNode != dummyTail_->prev){
                removeNode(valueNode);
                insertAtTail(valueNode);
            }

        } else {
            // Insert new node
            if(size_ == capacity_){
                // Remove least recently used node
                Node* nodeToDelete = dummyHead_->next;
                removeNode(nodeToDelete);
                nodeMap_.erase(nodeToDelete->key);
                delete(nodeToDelete);
                size_--;
            }

            Node* newNode = new Node(key, value);
            insertAtTail(newNode);
            nodeMap_.emplace(newNode->key, newNode);
            size_++;
        }
    }

    ~LRUCache() {
        auto current = dummyHead_;

        while(current){
            Node* nodeToDelete = current;
            current = current->next;
            delete nodeToDelete;
        }
    }
};