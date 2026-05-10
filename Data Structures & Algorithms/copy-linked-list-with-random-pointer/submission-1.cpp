/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        std::unordered_map<Node*, Node*> linkMap;

        Node dummyNode(-1);
        Node* newList = &dummyNode;

        Node* current = head;
        while(current){
            Node* newNode = new Node(current->val);
            linkMap[current] = newNode;
            current = current->next;
        }

        current = head;
        while(current){
            // Insert nodes one by one
            newList->next = linkMap[current];
            newList = newList->next;

            // Link random nodes
            newList->random = linkMap[current->random];

            current = current->next;
        }
        return dummyNode.next;

    }
};
