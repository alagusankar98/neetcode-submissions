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
        ListNode* middleNode = head;
    ListNode* fast = head;
    ListNode* middlePrev = nullptr;

    while(fast && fast->next){
        middlePrev = middleNode;
        middleNode = middleNode->next;
        fast = fast->next->next;
    }

    if(middlePrev){
        middlePrev->next = nullptr;
    } else {
        return;
    }

    // Reverse from middle node
    ListNode* revHead = nullptr;
    while(middleNode){
        auto next = middleNode->next;
        middleNode->next = revHead;
        revHead = middleNode;
        middleNode = next;
    }

    // Interweave head and revHead (revHead has equal or one element greater)
    ListNode dummyNode;
    ListNode* newList = &dummyNode;
    while(head && revHead){
        newList->next = head;
        head = head->next;
        newList = newList->next;

        newList->next = revHead;
        revHead = revHead->next;
        newList = newList->next;
    }
    newList->next = revHead;
    head = dummyNode.next;
    }
};
