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
        Node dummyNode(-1);
        Node* copyList = &dummyNode;
        Node* current = head;

        std::unordered_map<Node*, Node*> linkMap;

        while(current){
            Node* newNode = new Node(current->val);
            copyList->next = newNode;
            linkMap[current] = newNode;
            copyList = copyList->next;
            current = current->next;
        }

        // Link random nodes
        current = head;
        while(current){
            if(current->random){
                Node* copyNode = linkMap[current];
                copyNode->random = linkMap[current->random];
            }
            current = current->next;
        }

        return dummyNode.next;
    }
};
