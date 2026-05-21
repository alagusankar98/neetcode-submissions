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
        Node* current = head;

        while(current){
            Node* newNode = new Node(current->val);
            Node* nextNode = current->next;
            current->next = newNode;
            newNode->next = nextNode;
            current = nextNode;
        }

        // Link random nodes
        current = head;
        while(current && current->next){
            if(current->random){
                Node* copyNode = current->next;
                copyNode->random = current->random->next;
            }
            current = current->next->next;
        }

        Node dummyNode(-1);
        Node* copyList = &dummyNode;
        // Unweave list
        current = head;
        while(current && current->next){
            Node* nextNode = current->next->next;
            
            copyList->next = current->next;
            copyList = copyList->next;

            current->next = nextNode;
            current = nextNode;
        }

        return dummyNode.next;
    }
};
