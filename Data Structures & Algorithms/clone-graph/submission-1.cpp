/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
#include <cassert>
class Solution {
private:
    std::pair<Node*, bool> add_or_get_node(Node* node, std::array<Node*, 101>& seen){
        assert(node->val <= 100);
        bool isNew = !seen[node->val];
        if(isNew){
            seen[node->val] = new Node(node->val);
        }
        return {seen[node->val], isNew};
    }
public:
    Node* cloneGraph(Node* node) {
        if(!node) return nullptr;
        std::vector<Node*> nodeVector;
        nodeVector.reserve(100);
        std::array<Node*, 101> seen{};

        auto [root, _] = add_or_get_node(node, seen);
        nodeVector.push_back(node);
        std::size_t read = 0;
        
        while(read < nodeVector.size()){
            Node* origNode = nodeVector[read];
            read++;
            Node* copyNode = seen[origNode->val];
            copyNode->neighbors.reserve(origNode->neighbors.size());

            for(auto& neighborNode : origNode->neighbors){
                // Process neighbor node next in queue if it is not processed already
                auto [neighborCopyNode, isNew] = add_or_get_node(neighborNode, seen);
                if(isNew) nodeVector.push_back(neighborNode);
                copyNode->neighbors.push_back(neighborCopyNode);
            }
        }

        return root;
    }
};
