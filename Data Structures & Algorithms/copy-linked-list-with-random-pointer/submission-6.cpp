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
        Node* newList = &dummyNode;
        
        Node* current = head;
        while(current){
            Node* nextNode = current->next;
            Node* newNode = new Node(current->val);
            current->next = newNode;
            newNode->next = nextNode;
            current = nextNode;
        }

        current = head;
        while(current){
            Node* copyNode = current->next;
            if(current->random){
                copyNode->random = current->random->next;
            }
            current = copyNode->next;
        }

        current = head;
        while(current){
            Node* copyNode = current->next;
            newList->next = copyNode;
            newList = newList->next;
            current = copyNode->next;
        }

        return dummyNode.next;
    }
};
