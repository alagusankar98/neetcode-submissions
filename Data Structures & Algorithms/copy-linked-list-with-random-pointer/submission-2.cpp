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

        Node dummyNode(-1);
        Node* newList = &dummyNode;

        Node* current = head;
        while(current){
            Node* newNode = new Node(current->val);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }

        current = head;
        while(current && current->next){
            // Link random nodes
            if(current->random){
                current->next->random = current->random->next;// linkMap[current->random];
            }
            current = current->next->next;
        }

        current = head;
        while(current && current->next){
            // Insert nodes one by one
            Node* removeNode = current->next;
            newList->next = removeNode;
            newList = newList->next;

            current->next = removeNode->next;

            current = current->next;
        }
        return dummyNode.next;

    }
};
