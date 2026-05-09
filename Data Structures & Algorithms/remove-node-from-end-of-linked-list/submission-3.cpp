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
        auto current = head;
        while(current){
            std::cout << current->val << "  ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        // print(head);
        
        ListNode dummyNode;
        dummyNode.next = head;

        ListNode* current = head;
        
        // print(current);
        for(size_t i = 0; i < n; i++){
            current = current->next;
            // if(!current) Should not reach. If so, n exceeds actual length of linked list
        }

        // print(current);

        ListNode* prevNode = &dummyNode;

        while(current){
            prevNode = prevNode->next;
            current = current->next;
        }
        print(prevNode);

        ListNode* nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        nodeToDelete->next = nullptr; // Ideally should call "delete nodeToDelete" instead of just unlink

        return dummyNode.next;
    }
};
