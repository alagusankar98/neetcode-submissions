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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;

        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* current = head;
        for(size_t i = 0; i < n; i++){
            current = current->next;
        }

        ListNode* prevNode = &dummyNode;
        while(current){
            prevNode = prevNode->next;
            current = current->next;
        }

        ListNode* nodeToDelete = prevNode->next;
        prevNode->next = nodeToDelete->next;
        delete nodeToDelete;

        return dummyNode.next;
    }
};
