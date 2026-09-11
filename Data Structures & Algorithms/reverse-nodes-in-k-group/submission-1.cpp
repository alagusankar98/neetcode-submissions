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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummyNode;
        dummyNode.next = head;

        ListNode* lastNode = &dummyNode;
        while(true){
            ListNode* prevNode = lastNode;
            for(int i = 0; (i < k) && lastNode; i++){
                lastNode = lastNode->next;
            }
            if(!lastNode) break;

            // Unlink last node of current k group
            ListNode* nextGroupNode = lastNode->next;
            lastNode->next = nullptr;

            // Reverse from first node till unlinked node
            ListNode* head = prevNode->next;
            ListNode* revHead = nullptr;
            ListNode* current = head;
            while(current){
                ListNode* next = current->next;
                current->next = revHead;
                revHead = current;
                current = next;
            }
            head->next = nextGroupNode;
            prevNode->next = revHead;
            lastNode = head;
        }
        return dummyNode.next;
    }
};
