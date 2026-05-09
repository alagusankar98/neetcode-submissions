/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    void print(ListNode* head){
        ListNode* current = head;
        while(current){
            std::cout << current->val << "  ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    void reorderList(ListNode* head) {
        if(!head || !head->next) return;

        int length = 0;
        
        ListNode* middleNode = head;
        ListNode* fast = head;
        ListNode* firstHalfTail = head;

        // Find Middle Node
        while(fast && fast->next){
            fast = fast->next->next;
            firstHalfTail = middleNode;
            middleNode = middleNode->next;
        }

        // Cut-off first half list
        firstHalfTail->next = nullptr;
        // print(head);
        // print(middleNode);

        // Reverse list from middle node
        ListNode* prev = nullptr;
        ListNode* current = middleNode;

        while(current){
            auto nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }

        ListNode* middleRevHead = prev;

        // Merge Lists
        ListNode dummyNode;
        ListNode* newList = &dummyNode;
        current = head;
        bool first = true;

        while(current && middleRevHead){
            if(first){
                newList->next = current;
                current = current->next;
            } else {
                newList->next = middleRevHead;
                middleRevHead = middleRevHead->next;
            }
            newList = newList->next;
            first = !first;
        }

        newList->next = current ? current : middleRevHead;

        head = dummyNode.next;

    }
};
