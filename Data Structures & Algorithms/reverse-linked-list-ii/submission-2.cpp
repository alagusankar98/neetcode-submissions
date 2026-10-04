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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        ListNode dummyNode;
        dummyNode.next = head;

        ListNode* current = &dummyNode;

        for(size_t i = 1; (i < left && current); i++){
            current = current->next;
        }

        ListNode* revPrevNode = current;
        ListNode* revFirstNode = revPrevNode->next;

        const int n = right - left;

        for(size_t i = 0; (i <= n && current); i++){
            current = current->next;
        }

        ListNode* revNextNode = current->next;
        current->next = nullptr;

        // Reverse nodes
        ListNode* revHead = nullptr;
        current = revFirstNode;
        while(current){
            ListNode* next = current->next;
            current->next = revHead;
            revHead = current;
            current = next;
        }

        revFirstNode->next = revNextNode;
        revPrevNode->next = revHead;

        return dummyNode.next;

    }
};