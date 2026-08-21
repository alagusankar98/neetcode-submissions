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
    void reorderList(ListNode* head) {
    if(!head ||!head->next) return;

    ListNode* middleNode = head;
    ListNode* fast = head->next;

    while(fast && fast->next){
        middleNode = middleNode->next;
        fast = fast->next->next;
    }

    // First half of list is now >= Second Half because of changed initialization
    // 'middleNode' points to exactly floor(n/2)th node
    ListNode* secondHead = middleNode->next;
    middleNode->next = nullptr;

    // Reverse from middle node
    ListNode* revHead = nullptr;
    while(secondHead){
        auto next = secondHead->next;
        secondHead->next = revHead;
        revHead = secondHead;
        secondHead = next;
    }

    // Interweave head and revHead (head has equal or one element greater)
    ListNode dummyNode;
    ListNode* newList = &dummyNode;
    while(revHead){
        newList->next = head;
        head = head->next;
        newList = newList->next;

        newList->next = revHead;
        revHead = revHead->next;
        newList = newList->next;
    }
    newList->next = head;
    head = dummyNode.next;
}
};
