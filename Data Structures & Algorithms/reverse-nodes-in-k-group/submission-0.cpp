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
    ListNode* getNode(ListNode* node, int k){
        auto current = node;
        size_t nodeCount = 0;
        while(current && nodeCount < k){
            current = current->next;
            nodeCount++;
        }
        return current;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !head->next || k < 2) return head;

        ListNode dummyNode;
        dummyNode.next = head;
        ListNode* prev = &dummyNode;
        ListNode* current = head;

        while(current){
            ListNode* KthNode = getNode(prev, k);

            if(!KthNode) break;

            // Store the old head
            auto oldHead = current;

            // Reverse nodes
            auto revHead = prev;
            while(revHead != KthNode){
                auto nextNode = current->next;
                current->next = revHead;
                revHead = current;
                current = nextNode;
            }

            oldHead->next = current;

            prev->next = revHead;
            prev = oldHead;
        }

        return dummyNode.next;
    }
};
